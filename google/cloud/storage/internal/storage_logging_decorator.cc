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

#include "google/cloud/storage/internal/storage_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/internal/streaming_read_rpc_logging.h"
#include "google/cloud/internal/streaming_write_rpc_logging.h"
#include "google/cloud/status_or.h"
#include <google/storage/v2/storage.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace storage {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace internal {

StorageLogging::StorageLogging(std::shared_ptr<StorageStub> child,
                               TracingOptions tracing_options,
                               std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

std::unique_ptr<google::cloud::internal::StreamingReadRpc<
    google::storage::v2::ReadObjectResponse>>
StorageLogging::ReadObject(
    std::unique_ptr<grpc::ClientContext> context,
    google::storage::v2::ReadObjectRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](std::unique_ptr<grpc::ClientContext> context,
             google::storage::v2::ReadObjectRequest const& request)
          -> std::unique_ptr<google::cloud::internal::StreamingReadRpc<
              google::storage::v2::ReadObjectResponse>> {
        auto stream = child_->ReadObject(std::move(context), request);
        if (components_.count("rpc-streams") > 0) {
          stream = absl::make_unique<
              google::cloud::internal::StreamingReadRpcLogging<
                  google::storage::v2::ReadObjectResponse>>(
              std::move(stream), tracing_options_,
              google::cloud::internal::RequestIdForLogging());
        }
        return stream;
      },
      std::move(context), request, __func__, tracing_options_);
}

std::unique_ptr<::google::cloud::internal::StreamingWriteRpc<
    google::storage::v2::WriteObjectRequest,
    google::storage::v2::WriteObjectResponse>>
StorageLogging::WriteObject(std::unique_ptr<grpc::ClientContext> context) {
  using LoggingStream = ::google::cloud::internal::StreamingWriteRpcLogging<
      google::storage::v2::WriteObjectRequest,
      google::storage::v2::WriteObjectResponse>;

  auto request_id = google::cloud::internal::RequestIdForLogging();
  GCP_LOG(DEBUG) << __func__ << "(" << request_id << ")";
  auto stream = child_->WriteObject(std::move(context));
  if (components_.count("rpc-streams") > 0) {
    stream = absl::make_unique<LoggingStream>(
        std::move(stream), tracing_options_, std::move(request_id));
  }
  return stream;
}

StatusOr<google::storage::v2::StartResumableWriteResponse>
StorageLogging::StartResumableWrite(
    grpc::ClientContext& context,
    google::storage::v2::StartResumableWriteRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::storage::v2::StartResumableWriteRequest const& request) {
        return child_->StartResumableWrite(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::storage::v2::QueryWriteStatusResponse>
StorageLogging::QueryWriteStatus(
    grpc::ClientContext& context,
    google::storage::v2::QueryWriteStatusRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::storage::v2::QueryWriteStatusRequest const& request) {
        return child_->QueryWriteStatus(context, request);
      },
      context, request, __func__, tracing_options_);
}

}  // namespace internal
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage
}  // namespace cloud
}  // namespace google
