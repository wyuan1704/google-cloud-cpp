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
// source: google/cloud/sql/v1/cloud_sql_backup_runs.proto

#include "google/cloud/sqladmin/internal/sql_backup_runs_auth_decorator.h"
#include <google/cloud/sql/v1/cloud_sql_backup_runs.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace sqladmin_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SqlBackupRunsServiceAuth::SqlBackupRunsServiceAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<SqlBackupRunsServiceStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::sql::v1::Operation> SqlBackupRunsServiceAuth::Delete(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlBackupRunsDeleteRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->Delete(context, request);
}

StatusOr<google::cloud::sql::v1::BackupRun> SqlBackupRunsServiceAuth::Get(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlBackupRunsGetRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->Get(context, request);
}

StatusOr<google::cloud::sql::v1::Operation> SqlBackupRunsServiceAuth::Insert(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlBackupRunsInsertRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->Insert(context, request);
}

StatusOr<google::cloud::sql::v1::BackupRunsListResponse>
SqlBackupRunsServiceAuth::List(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlBackupRunsListRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->List(context, request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace sqladmin_internal
}  // namespace cloud
}  // namespace google
