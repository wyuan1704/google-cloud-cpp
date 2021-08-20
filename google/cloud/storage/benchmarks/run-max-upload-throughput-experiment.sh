#!/usr/bin/env bash
#
# Copyright 2021 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Usage: run-increasing-threads-experiment.sh [options] host:api [host:api...]
#
#   Options:
#     --project=project         The project hosting the VMs and buckets
#     --zone=zone               The zone hosting the VMs
#     --bucket=name             A bucket with an existing dataset to run
#                               the benchmark. If not set, uses default
#                               based on the zone
#     --dataset-prefix=prefix   The common prefix for the objects in the
#                               dataset
#     --object-count=n          Number of objects uploaded in each iteration
#     --iteration-count=n       Number of iterations in each run
#     --task-threads=n          Number of threads in each task (aka processes)
#     --task-count=n            Number of tasks (aka processes). Sometimes this
#                               is called the job size
#     -h|--help                 Print this help message
#

set -eu

function print_usage() {
  # Extracts the usage from the file comment starting at line 17.
  sed -n '17,/^$/s/^# \?//p' "$0"
}

# Use getopt to parse and normalize all the args.
PARSED="$(getopt -a \
  --options="h" \
  --longoptions="project:,zone:,bucket:,dataset-prefix:,object-count:,iteration-count:,task-threads:,task-count:,ssh-delay:,help" \
  --name="$(basename "$0")" \
  -- "$@")"
eval set -- "${PARSED}"

PROJECT="p3rf-gcs"
ZONE="us-central1-a"
BUCKET=""
DATASET_PREFIX="aggregate-upload-throughput-bm/"
ITERATION_COUNT=2
OBJECT_COUNT=100
TASK_THREADS=4
TASK_COUNT=4
SSH_DELAY=0.5

while true; do
  case "$1" in
  --project)
    PROJECT="$2"
    shift 2
    ;;
  --zone)
    ZONE="$2"
    shift 2
    ;;
  --bucket)
    BUCKET="$2"
    shift 2
    ;;
  --dataset-prefix)
    DATASET_PREFIX="$2"
    shift 2
    ;;
  --iteration-count)
    ITERATION_COUNT="$2"
    shift 2
    ;;
  --object-count)
    OBJECT_COUNT="$2"
    shift 2
    ;;
  --task-threads)
    TASK_THREADS="$2"
    shift 2
    ;;
  --task-count)
    TASK_COUNT="$2"
    shift 2
    ;;
  --ssh-delay)
    SSH_DELAY="$2"
    shift 2
    ;;
  -h | --help)
    print_usage
    exit 0
    ;;
  --)
    shift
    break
    ;;
  esac
done

if [[ $# -eq 0 ]]; then
  echo "No APIs specified"
  print_usage
  exit 1
fi

readonly RUNS=("${@}")
readonly ZONE
readonly DATASET_PREFIX
readonly ITERATION_COUNT
readonly OBJECT_COUNT
readonly TASK_THREADS
readonly TASK_COUNT

FULL_REGION="$(gcloud compute zones describe --project="${PROJECT}" "${ZONE}" --format="value(region)")"
readonly FULL_REGION
readonly REGION="${FULL_REGION##*/}"

if [[ -z "${BUCKET}" ]]; then
  BUCKET="cloud-cpp-testing-coryan-p3rf-${REGION}"
fi
readonly BUCKET

# TODO(coryan) - cleanup debugging
echo "RUNS=" "${RUNS[@]}"
echo "ZONE=${ZONE}"
echo "DATASET_PREFIX=${DATASET_PREFIX}"
echo "FULL_REGION=${FULL_REGION}"
echo "REGION=${REGION}"
echo "BUCKET=${BUCKET}"
echo "ITERATION_COUNT=${ITERATION_COUNT}"
echo "OBJECT_COUNT=${OBJECT_COUNT}"
echo "TASK_THREADS=${TASK_THREADS}"
echo "TASK_COUNT=${TASK_COUNT}"
echo "SSH_DELAY=${SSH_DELAY}"

readonly EXPERIMENT="${HOME}/benchmarks/max-upload-throughput/${ZONE}"
mkdir -p "${EXPERIMENT}"

function start_benchmark_instance {
  local -r host="$1"
  local -r task_threads="$2"
  local -r object_count="$3"
  local -r api="$4"
  local -r grpc_config="$5"
  local -r labels="$6"

  local job="${labels//,/-}"
  job="${job//:/-}"
  local -r log="${EXPERIMENT}/${job}-${api}-${host}.txt"
  echo "${log}"

  ssh -A -o "ProxyCommand=corp-ssh-helper %h %p" "${host}.${ZONE}.${PROJECT}" \
    docker run \
      --network=host --pull always --rm \
      --env XCLOUD_STORAGE_ENABLE_TRACING="raw-client" \
      --env XGOOGLE_CLOUD_CPP_EXPERIMENTAL_LOG_CONFIG="lastN,128000,WARNING" \
      gcr.io/p3rf-gcs/cloud-cpp-storage-benchmarks:latest \
      /r/aggregate_upload_throughput_benchmark \
        --client-per-thread="true" \
        --grpc-channel-count="1" \
        --rest-http-version="1.1" \
        --bucket-name="${BUCKET}" \
        --object-prefix="${DATASET_PREFIX}" \
        --object-count="${object_count}" \
        --iteration-count="${ITERATION_COUNT}" \
        --minimum-object-size=256MiB \
        --maximum-object-size=256MiB \
        --use-resumable-upload=true \
        --resumable-upload-chunk-size=64MiB \
        --labels="${labels},host:${host},zone:${ZONE}" \
        --api="${api}" \
        --grpc-plugin-config="${grpc_config}" \
        --thread-count="${task_threads}" \
    > "${log}" 2>"${log}.log" </dev/null &
}

function main {
  local object_count=$((OBJECT_COUNT / TASK_COUNT))
  if [[ ${object_count} -eq 0 ]]; then object_count=1; fi
  readonly object_count
  local -r size=$((TASK_THREADS * TASK_COUNT))
  local i

  for i in $(seq 1 "${TASK_COUNT}"); do
    for run in "${RUNS[@]}"; do
      local host="${run%%:*}"
      local config="${run##*:}"
      local api="${config%%/*}"
      local grpc_config="${config##*/}"
      if [[ -z "${grpc_config}" ]]; then grpc_config="dp"; fi
      start_benchmark_instance "${host}" "${TASK_THREADS}" "${object_count}" "${api}" "${grpc_config}" \
          "max-throughput:${size},task:${i},task-count:${TASK_COUNT},host-count:1"
      sleep "${SSH_DELAY}"
    done
  done
  wait
}

main
