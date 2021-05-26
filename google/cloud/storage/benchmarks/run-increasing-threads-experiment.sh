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
# Usage: run-increasing-threads-experiment.sh [options] api...
#
#   Options:
#     --project=project         The project hosting the VMs and buckets
#     --zone=zone               The zone hosting the VMs
#     --bucket=name             A bucket with an existing dataset to run
#                               the benchmark. If not set, uses default
#                               based on the zone
#     --dataset-prefix=prefix   The common prefix for the objects in the
#                               dataset
#     --iteration-count=n       Number of iterations in each run
#     --repeats-per-iteration=n Repeat the download `n` times in each
#                               iteration
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
  --longoptions="project:,zone:,iteration-count:,repeats-per-iteration:,help" \
  --name="$(basename "$0")" \
  -- "$@")"
eval set -- "${PARSED}"

PROJECT="p3rf-gcs"
ZONE="us-central1-a"
BUCKET=""
DATASET_PREFIX="dataset-with-10-objects-of-1GiB/"
ITERATION_COUNT=2
REPEATS_PER_ITERATION=100

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
  --repeats-per-iteration)
    REPEATS_PER_ITERATION="$2"
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

readonly APIS=("${@}")
readonly ZONE
readonly ITERATION_COUNT
readonly REPEATS_PER_ITERATION
readonly DATASET_PREFIX

FULL_REGION="$(gcloud compute zones describe --project="${PROJECT}" "${ZONE}" --format="value(region)")"
readonly FULL_REGION
readonly REGION="${FULL_REGION##*/}"

readarray -t HOSTS < <(gcloud compute instances list --project="${PROJECT}" --zones="${ZONE}" --filter=name:cloud-cpp-bm --format='value(name)')
readonly HOSTS
if [[ "${#HOSTS[@]}" -lt 5 ]]; then
  echo "This program requires at least 5 VMs in the ${ZONE} zone"
  exit 1
fi

if [[ -z "${BUCKET}" ]]; then
  BUCKET="cloud-cpp-testing-coryan-p3rf-${REGION}"
fi
readonly BUCKET

# TODO(coryan) - cleanup debugging
echo "APIS=" "${APIS[@]}"
echo "HOSTS=" "${HOSTS[@]}"
echo "ZONE=${ZONE}"
echo "ITERATION_COUNT=${ITERATION_COUNT}"
echo "REPEATS_PER_ITERATION=${REPEATS_PER_ITERATION}"
echo "DATASET_PREFIX=${DATASET_PREFIX}"
echo "FULL_REGION=${FULL_REGION}"
echo "REGION=${REGION}"
echo "BUCKET=${BUCKET}"

readonly EXPERIMENT="${HOME}/benchmarks/increasing-threads"
mkdir -p "${EXPERIMENT}"

function start_benchmark_instance {
  local -r host="$1"
  local -r task_threads="$2"
  local -r repeats="$3"
  local -r api="$4"
  local -r labels="$5"

  local job="${labels//,/-}"
  job="${job//:/-}"
  local -r log="${EXPERIMENT}/${job}-${api}-${host}.txt"
  echo "${log}"

  ssh -A -o "ProxyCommand=corp-ssh-helper %h %p" "${host}.${ZONE}.${PROJECT}" \
    docker run \
      --network=host --pull always --rm \
      gcr.io/p3rf-gcs/cloud-cpp-storage-benchmarks:latest \
      /r/aggregate_throughput_benchmark \
        --client-per-thread="true" \
        --grpc-channel-count="2" \
        --grpc-plugin-config="dp" \
        --rest-http-version="1.1" \
        --bucket-name="${BUCKET}" \
        --object-prefix="${DATASET_PREFIX}" \
        --iteration-count="${ITERATION_COUNT}" \
        --labels="${labels},host:${host},zone:${ZONE}" \
        --api="${api}" \
        --repeats-per-iteration="${repeats}" \
        --thread-count="${task_threads}" \
    > "${log}" </dev/null &
}

function start_multi_host_instances {
  local -r task_threads="$1"
  local -r label="$2"
  local -r api="$3"
  shift 3
  local -a -r hosts=("$@")
  local host_count
  host_count="$(printf "%s\n" "${hosts[@]}" | sort -u | wc -l)"

  local -r job_size="${#hosts[@]}"
  local repeats=$((REPEATS_PER_ITERATION / job_size))
  if [[ ${repeats} -eq 0 ]]; then repeats=1; fi
  local count=1
  last_host=""
  for host in "${hosts[@]}"; do
    start_benchmark_instance "${host}" "${task_threads}" "${repeats}" "${api}" \
      "scenario:${label},task:${count},job-size:${job_size},host-count:${host_count}"
    # Avoid SSH failures
    [[ "${last_host}" != "${host}" ]] || sleep 2
    last_host="${host}"
    count=$((count + 1))
  done
}

for api in "${APIS[@]}"; do
  count=0
  for task_threads in 64 8 56 16; do
    host="${HOSTS[$count]}"
    start_multi_host_instances "${task_threads}" \
      "singleprocess:${task_threads}" "${api}" "${host}"
    count=$((count + 1))
  done
  wait
done

for api in "${APIS[@]}"; do
  count=0
  for task_threads in 48 24 40 32; do
    host="${HOSTS[$count]}"
    start_multi_host_instances "${task_threads}" \
      "singleprocess:${task_threads}" "${api}" "${host}"
    count=$((count + 1))
  done
  wait
done

for api in "${APIS[@]}"; do
  for host_threads in 64 8 56 16; do
    count=0
    for task_threads in 8 4; do
      process_count=$((host_threads / task_threads))
      host="${HOSTS[$count]}"
      list=()
      for _ in $(seq 1 ${process_count}); do list+=("${host}"); done
      start_multi_host_instances "${task_threads}" \
        "singlehost:${task_threads}" "${api}" "${list[@]}"
      count=$((count + 1))
      wait
    done
  done
done

for api in "${APIS[@]}"; do
  for host_threads in 48 24 40 32; do
    count=0
    for task_threads in 8 4; do
      process_count=$((host_threads / task_threads))
      host="${HOSTS[$count]}"
      list=()
      for _ in $(seq 1 ${process_count}); do list+=("${host}"); done
      start_multi_host_instances "${task_threads}" \
        "singlehost:${task_threads}" "${api}" "${list[@]}"
      count=$((count + 1))
      wait
    done
  done
done

#for task_threads in 16 12 10 8; do
#  for api in "${APIS[@]}"; do
#    start_multi_host_instances "${task_threads}" \
#      "multihost:${task_threads}" "${api}" "${HOSTS[@]:0:4}"
#    wait
#  done
#done

#for task_threads in 6 4 2; do
#  for api in "${APIS[@]}"; do
#    start_multi_host_instances "${task_threads}" \
#      "multihost:${task_threads}" "${api}" "${HOSTS[@]:0:4}"
#    wait
#  done
#done
