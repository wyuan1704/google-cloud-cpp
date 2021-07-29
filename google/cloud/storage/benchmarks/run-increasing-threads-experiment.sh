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

set -eu

readonly API="$1"

readonly OBJECT_COUNT="10"
readonly OBJECT_PREFIX="dataset-with-${OBJECT_COUNT}-objects-of-1GiB/"
readonly EXPERIMENT="${HOME}/benchmarks/increasing-threads/${API}"
readonly REGION="southamerica-east1"
readonly BUCKET="cloud-cpp-testing-coryan-p3rf-${REGION}"

mkdir -p "${EXPERIMENT}"

readonly ITERATION_COUNT=5
readonly REPEATS_PER_ITERATION=96

function start_benchmark_instance {
  local -r host="$1"
  local -r bucket="$2"
  local -r task_id="$3"
  local -r task_threads="$4"
  local -r job="$5"
  local -r repeats="$6"

  local -r log="${EXPERIMENT}/${job}-${host}-${task_id}.${API}.txt"
  echo "${log}"

  ssh -A -o "ProxyCommand=corp-ssh-helper %h %p" "${host}" \
    docker run \
      --network=host --pull always --rm \
      gcr.io/p3rf-gcs/cloud-cpp-storage-benchmarks:latest \
      /r/aggregate_throughput_benchmark \
        --grpc-channel-count="${task_threads}" --grpc-plugin-config="dp" \
        --api="${API}" \
        --object-prefix="${OBJECT_PREFIX}" \
        --iteration-count="${ITERATION_COUNT}" \
        --repeats-per-iteration="${repeats}" \
        --bucket-name="${bucket}" \
        --thread-count="${task_threads}" \
    > "${log}" </dev/null &
}

function start_multi_host_instances {
  local -r bucket="$1"
  local -r threads="$2"
  local -r label="$3"
  shift 3
  local -a -r hosts=("$@")
  local host_count
  host_count="$(printf "%s\n" "${hosts[@]}" | sort -u | wc -l)"

  local -r total="${#hosts[@]}"
  local -r task_threads=$((threads / total))
  local -r repeats=$((REPEATS_PER_ITERATION / total))
  count=1
  for host in "${hosts[@]}"; do
    start_benchmark_instance "${host}" "${bucket}" "label-${label}-task-${count}-job-${total}-hosts-${host_count}" "${task_threads}" "${threads}" "${repeats}"
    count=$((count + 1))
  done
}

readonly HOSTS=(
  "cloud-cpp-bm-01.${REGION}-a.p3rf-gcs"
  "cloud-cpp-bm-02.${REGION}-a.p3rf-gcs"
  "cloud-cpp-bm-03.${REGION}-a.p3rf-gcs"
  "cloud-cpp-bm-04.${REGION}-a.p3rf-gcs"
  "cloud-cpp-bm-05.${REGION}-a.p3rf-gcs"
)
for total_threads in 64 48 32 16 8 96 80; do
  start_multi_host_instances "${BUCKET}" "${total_threads}" "multihost4" "${HOSTS[@]:0:4}"
  wait
  start_multi_host_instances "${BUCKET}" "${total_threads}" "singleprocess" "${HOSTS[4]}"
  start_multi_host_instances "${BUCKET}" "${total_threads}" "singlehost" "${HOSTS[3]}" "${HOSTS[3]}" "${HOSTS[3]}" "${HOSTS[3]}"
  start_multi_host_instances "${BUCKET}" "${total_threads}" "multihost2" "${HOSTS[@]:0:2}"
  wait
done
