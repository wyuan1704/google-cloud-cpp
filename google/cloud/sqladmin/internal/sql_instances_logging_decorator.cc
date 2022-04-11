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
// source: google/cloud/sql/v1/cloud_sql_instances.proto

#include "google/cloud/sqladmin/internal/sql_instances_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/sql/v1/cloud_sql_instances.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace sqladmin_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SqlInstancesServiceLogging::SqlInstancesServiceLogging(
    std::shared_ptr<SqlInstancesServiceStub> child,
    TracingOptions tracing_options, std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceLogging::AddServerCa(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesAddServerCaRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesAddServerCaRequest const&
                 request) { return child_->AddServerCa(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation> SqlInstancesServiceLogging::Clone(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesCloneRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesCloneRequest const& request) {
        return child_->Clone(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation> SqlInstancesServiceLogging::Delete(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesDeleteRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesDeleteRequest const& request) {
        return child_->Delete(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceLogging::DemoteMaster(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesDemoteMasterRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesDemoteMasterRequest const&
                 request) { return child_->DemoteMaster(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation> SqlInstancesServiceLogging::Export(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesExportRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesExportRequest const& request) {
        return child_->Export(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceLogging::Failover(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesFailoverRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::sql::v1::SqlInstancesFailoverRequest const& request) {
        return child_->Failover(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::DatabaseInstance>
SqlInstancesServiceLogging::Get(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesGetRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesGetRequest const& request) {
        return child_->Get(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation> SqlInstancesServiceLogging::Import(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesImportRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesImportRequest const& request) {
        return child_->Import(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation> SqlInstancesServiceLogging::Insert(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesInsertRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesInsertRequest const& request) {
        return child_->Insert(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::InstancesListResponse>
SqlInstancesServiceLogging::List(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesListRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesListRequest const& request) {
        return child_->List(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::InstancesListServerCasResponse>
SqlInstancesServiceLogging::ListServerCas(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesListServerCasRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesListServerCasRequest const&
                 request) { return child_->ListServerCas(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation> SqlInstancesServiceLogging::Patch(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesPatchRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesPatchRequest const& request) {
        return child_->Patch(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceLogging::PromoteReplica(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesPromoteReplicaRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesPromoteReplicaRequest const&
                 request) { return child_->PromoteReplica(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceLogging::ResetSslConfig(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesResetSslConfigRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesResetSslConfigRequest const&
                 request) { return child_->ResetSslConfig(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation> SqlInstancesServiceLogging::Restart(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesRestartRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::sql::v1::SqlInstancesRestartRequest const& request) {
        return child_->Restart(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceLogging::RestoreBackup(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesRestoreBackupRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesRestoreBackupRequest const&
                 request) { return child_->RestoreBackup(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceLogging::RotateServerCa(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesRotateServerCaRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesRotateServerCaRequest const&
                 request) { return child_->RotateServerCa(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceLogging::StartReplica(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesStartReplicaRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesStartReplicaRequest const&
                 request) { return child_->StartReplica(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceLogging::StopReplica(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesStopReplicaRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesStopReplicaRequest const&
                 request) { return child_->StopReplica(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceLogging::TruncateLog(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesTruncateLogRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesTruncateLogRequest const&
                 request) { return child_->TruncateLog(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation> SqlInstancesServiceLogging::Update(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesUpdateRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesUpdateRequest const& request) {
        return child_->Update(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::SslCert>
SqlInstancesServiceLogging::CreateEphemeral(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesCreateEphemeralCertRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](
          grpc::ClientContext& context,
          google::cloud::sql::v1::SqlInstancesCreateEphemeralCertRequest const&
              request) { return child_->CreateEphemeral(context, request); },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceLogging::RescheduleMaintenance(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesRescheduleMaintenanceRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::
                 SqlInstancesRescheduleMaintenanceRequest const& request) {
        return child_->RescheduleMaintenance(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::SqlInstancesVerifyExternalSyncSettingsResponse>
SqlInstancesServiceLogging::VerifyExternalSyncSettings(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesVerifyExternalSyncSettingsRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::
                 SqlInstancesVerifyExternalSyncSettingsRequest const& request) {
        return child_->VerifyExternalSyncSettings(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceLogging::StartExternalSync(
    grpc::ClientContext& context,
    google::cloud::sql::v1::SqlInstancesStartExternalSyncRequest const&
        request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesStartExternalSyncRequest const&
                 request) {
        return child_->StartExternalSync(context, request);
      },
      context, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace sqladmin_internal
}  // namespace cloud
}  // namespace google
