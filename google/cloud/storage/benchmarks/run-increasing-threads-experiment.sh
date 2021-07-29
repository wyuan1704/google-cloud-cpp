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
readonly REPEATS_PER_ITERATION=32

function start_benchmark_instance {
  local -r host="$1"
  local -r bucket="$2"
  local -r task_id="$3"
  local -r task_threads="$4"
  local -r total_threads="$5"
  local -r repeats="$6"

  local -r log="${EXPERIMENT}/${total_threads}-${host}-${task_id}.${API}.txt"
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

readonly SINGLE_PROCESS_HOST="cloud-cpp-bm-01.${REGION}-a.p3rf-gcs"
function start_single_process_instances {
  local -r bucket="$1"
  local -r threads="$2"

  start_benchmark_instance "${SINGLE_PROCESS_HOST}" "${bucket}" "1-of-1" "${threads}" "${threads}" "${REPEATS_PER_ITERATION}"
}

readonly MULTI_PROCESS_HOST="cloud-cpp-bm-02.${REGION}-a.p3rf-gcs"
function start_multi_process_instances {
  local -r bucket="$1"
  local -r threads="$2"

  local -r task_threads=$((threads / 4))
  local -r repeats=$((REPEATS_PER_ITERATION / 4))
  start_benchmark_instance "${MULTI_PROCESS_HOST}" "${bucket}" "1-of-4" "${task_threads}" "${threads}" "${repeats}"
  start_benchmark_instance "${MULTI_PROCESS_HOST}" "${bucket}" "2-of-4" "${task_threads}" "${threads}" "${repeats}"
  start_benchmark_instance "${MULTI_PROCESS_HOST}" "${bucket}" "3-of-4" "${task_threads}" "${threads}" "${repeats}"
  start_benchmark_instance "${MULTI_PROCESS_HOST}" "${bucket}" "4-of-4" "${task_threads}" "${threads}" "${repeats}"
}

function start_multi_host_instances {
  local -r bucket="$1"
  local -r threads="$2"

  local -r task_threads=$((threads / 4))
  local -r repeats=$((REPEATS_PER_ITERATION / 4))
  start_benchmark_instance "cloud-cpp-bm-03.${REGION}-a.p3rf-gcs" "${bucket}" "1-of-4" "${task_threads}" "${threads}" "${repeats}"
  start_benchmark_instance "cloud-cpp-bm-04.${REGION}-a.p3rf-gcs" "${bucket}" "2-of-4" "${task_threads}" "${threads}" "${repeats}"
  start_benchmark_instance "cloud-cpp-bm-03.${REGION}-a.p3rf-gcs" "${bucket}" "3-of-4" "${task_threads}" "${threads}" "${repeats}"
  start_benchmark_instance "cloud-cpp-bm-04.${REGION}-a.p3rf-gcs" "${bucket}" "4-of-4" "${task_threads}" "${threads}" "${repeats}"
}

for total_threads in 16 32 48 64; do
  start_single_process_instances "${BUCKET}" "${total_threads}"
  start_multi_process_instances "${BUCKET}" "${total_threads}"
  start_multi_host_instances "${BUCKET}" "${total_threads}"
  wait
done
