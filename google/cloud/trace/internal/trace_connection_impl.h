// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/devtools/cloudtrace/v2/tracing.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_TRACE_INTERNAL_TRACE_CONNECTION_IMPL_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_TRACE_INTERNAL_TRACE_CONNECTION_IMPL_H

#include "google/cloud/trace/internal/trace_retry_traits.h"
#include "google/cloud/trace/internal/trace_stub.h"
#include "google/cloud/trace/trace_connection.h"
#include "google/cloud/trace/trace_connection_idempotency_policy.h"
#include "google/cloud/trace/trace_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/backoff_policy.h"
#include "google/cloud/options.h"
#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <memory>

namespace google {
namespace cloud {
namespace trace_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class TraceServiceConnectionImpl : public trace::TraceServiceConnection {
 public:
  ~TraceServiceConnectionImpl() override = default;

  TraceServiceConnectionImpl(
      std::unique_ptr<google::cloud::BackgroundThreads> background,
      std::shared_ptr<trace_internal::TraceServiceStub> stub, Options options);

  Options options() override { return options_; }

  Status BatchWriteSpans(
      google::devtools::cloudtrace::v2::BatchWriteSpansRequest const& request)
      override;

  StatusOr<google::devtools::cloudtrace::v2::Span> CreateSpan(
      google::devtools::cloudtrace::v2::Span const& request) override;

 private:
  std::unique_ptr<trace::TraceServiceRetryPolicy> retry_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<trace::TraceServiceRetryPolicyOption>()) {
      return options.get<trace::TraceServiceRetryPolicyOption>()->clone();
    }
    return options_.get<trace::TraceServiceRetryPolicyOption>()->clone();
  }

  std::unique_ptr<BackoffPolicy> backoff_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<trace::TraceServiceBackoffPolicyOption>()) {
      return options.get<trace::TraceServiceBackoffPolicyOption>()->clone();
    }
    return options_.get<trace::TraceServiceBackoffPolicyOption>()->clone();
  }

  std::unique_ptr<trace::TraceServiceConnectionIdempotencyPolicy>
  idempotency_policy() {
    auto const& options = internal::CurrentOptions();
    if (options.has<trace::TraceServiceConnectionIdempotencyPolicyOption>()) {
      return options
          .get<trace::TraceServiceConnectionIdempotencyPolicyOption>()
          ->clone();
    }
    return options_.get<trace::TraceServiceConnectionIdempotencyPolicyOption>()
        ->clone();
  }

  std::unique_ptr<google::cloud::BackgroundThreads> background_;
  std::shared_ptr<trace_internal::TraceServiceStub> stub_;
  Options options_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace trace_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_TRACE_INTERNAL_TRACE_CONNECTION_IMPL_H
