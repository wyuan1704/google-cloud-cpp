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
// source: google/cloud/websecurityscanner/v1/web_security_scanner.proto

#include "google/cloud/websecurityscanner/internal/web_security_scanner_auth_decorator.h"
#include <google/cloud/websecurityscanner/v1/web_security_scanner.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace websecurityscanner_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

WebSecurityScannerAuth::WebSecurityScannerAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<WebSecurityScannerStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::websecurityscanner::v1::ScanConfig>
WebSecurityScannerAuth::CreateScanConfig(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::CreateScanConfigRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->CreateScanConfig(context, request);
}

Status WebSecurityScannerAuth::DeleteScanConfig(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::DeleteScanConfigRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->DeleteScanConfig(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ScanConfig>
WebSecurityScannerAuth::GetScanConfig(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::GetScanConfigRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetScanConfig(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ListScanConfigsResponse>
WebSecurityScannerAuth::ListScanConfigs(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::ListScanConfigsRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListScanConfigs(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ScanConfig>
WebSecurityScannerAuth::UpdateScanConfig(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::UpdateScanConfigRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->UpdateScanConfig(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ScanRun>
WebSecurityScannerAuth::StartScanRun(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::StartScanRunRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->StartScanRun(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ScanRun>
WebSecurityScannerAuth::GetScanRun(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::GetScanRunRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetScanRun(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ListScanRunsResponse>
WebSecurityScannerAuth::ListScanRuns(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::ListScanRunsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListScanRuns(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ScanRun>
WebSecurityScannerAuth::StopScanRun(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::StopScanRunRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->StopScanRun(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ListCrawledUrlsResponse>
WebSecurityScannerAuth::ListCrawledUrls(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::ListCrawledUrlsRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListCrawledUrls(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::Finding>
WebSecurityScannerAuth::GetFinding(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::GetFindingRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetFinding(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ListFindingsResponse>
WebSecurityScannerAuth::ListFindings(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::ListFindingsRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListFindings(context, request);
}

StatusOr<google::cloud::websecurityscanner::v1::ListFindingTypeStatsResponse>
WebSecurityScannerAuth::ListFindingTypeStats(
    grpc::ClientContext& context,
    google::cloud::websecurityscanner::v1::ListFindingTypeStatsRequest const&
        request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->ListFindingTypeStats(context, request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace websecurityscanner_internal
}  // namespace cloud
}  // namespace google
