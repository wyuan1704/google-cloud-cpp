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

#include "google/cloud/sqladmin/internal/sql_instances_connection_impl.h"
#include "google/cloud/sqladmin/internal/sql_instances_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace sqladmin_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

SqlInstancesServiceConnectionImpl::SqlInstancesServiceConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<sqladmin_internal::SqlInstancesServiceStub> stub,
    Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(
          std::move(options),
          sqladmin_internal::SqlInstancesServiceDefaultOptions(
              SqlInstancesServiceConnection::options()))) {}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::AddServerCa(
    google::cloud::sql::v1::SqlInstancesAddServerCaRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->AddServerCa(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesAddServerCaRequest const&
                 request) { return stub_->AddServerCa(context, request); },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::Clone(
    google::cloud::sql::v1::SqlInstancesCloneRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->Clone(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesCloneRequest const& request) {
        return stub_->Clone(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::Delete(
    google::cloud::sql::v1::SqlInstancesDeleteRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->Delete(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesDeleteRequest const& request) {
        return stub_->Delete(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::DemoteMaster(
    google::cloud::sql::v1::SqlInstancesDemoteMasterRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DemoteMaster(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesDemoteMasterRequest const&
                 request) { return stub_->DemoteMaster(context, request); },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::Export(
    google::cloud::sql::v1::SqlInstancesExportRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->Export(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesExportRequest const& request) {
        return stub_->Export(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::Failover(
    google::cloud::sql::v1::SqlInstancesFailoverRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->Failover(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::sql::v1::SqlInstancesFailoverRequest const& request) {
        return stub_->Failover(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::DatabaseInstance>
SqlInstancesServiceConnectionImpl::Get(
    google::cloud::sql::v1::SqlInstancesGetRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->Get(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesGetRequest const& request) {
        return stub_->Get(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::Import(
    google::cloud::sql::v1::SqlInstancesImportRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->Import(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesImportRequest const& request) {
        return stub_->Import(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::Insert(
    google::cloud::sql::v1::SqlInstancesInsertRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->Insert(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesInsertRequest const& request) {
        return stub_->Insert(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::InstancesListResponse>
SqlInstancesServiceConnectionImpl::List(
    google::cloud::sql::v1::SqlInstancesListRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->List(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesListRequest const& request) {
        return stub_->List(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::InstancesListServerCasResponse>
SqlInstancesServiceConnectionImpl::ListServerCas(
    google::cloud::sql::v1::SqlInstancesListServerCasRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->ListServerCas(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesListServerCasRequest const&
                 request) { return stub_->ListServerCas(context, request); },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::Patch(
    google::cloud::sql::v1::SqlInstancesPatchRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->Patch(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesPatchRequest const& request) {
        return stub_->Patch(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::PromoteReplica(
    google::cloud::sql::v1::SqlInstancesPromoteReplicaRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->PromoteReplica(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesPromoteReplicaRequest const&
                 request) { return stub_->PromoteReplica(context, request); },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::ResetSslConfig(
    google::cloud::sql::v1::SqlInstancesResetSslConfigRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->ResetSslConfig(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesResetSslConfigRequest const&
                 request) { return stub_->ResetSslConfig(context, request); },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::Restart(
    google::cloud::sql::v1::SqlInstancesRestartRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->Restart(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::sql::v1::SqlInstancesRestartRequest const& request) {
        return stub_->Restart(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::RestoreBackup(
    google::cloud::sql::v1::SqlInstancesRestoreBackupRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->RestoreBackup(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesRestoreBackupRequest const&
                 request) { return stub_->RestoreBackup(context, request); },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::RotateServerCa(
    google::cloud::sql::v1::SqlInstancesRotateServerCaRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->RotateServerCa(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesRotateServerCaRequest const&
                 request) { return stub_->RotateServerCa(context, request); },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::StartReplica(
    google::cloud::sql::v1::SqlInstancesStartReplicaRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->StartReplica(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesStartReplicaRequest const&
                 request) { return stub_->StartReplica(context, request); },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::StopReplica(
    google::cloud::sql::v1::SqlInstancesStopReplicaRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->StopReplica(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesStopReplicaRequest const&
                 request) { return stub_->StopReplica(context, request); },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::TruncateLog(
    google::cloud::sql::v1::SqlInstancesTruncateLogRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->TruncateLog(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesTruncateLogRequest const&
                 request) { return stub_->TruncateLog(context, request); },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::Update(
    google::cloud::sql::v1::SqlInstancesUpdateRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->Update(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesUpdateRequest const& request) {
        return stub_->Update(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::SslCert>
SqlInstancesServiceConnectionImpl::CreateEphemeral(
    google::cloud::sql::v1::SqlInstancesCreateEphemeralCertRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CreateEphemeral(request),
      [this](
          grpc::ClientContext& context,
          google::cloud::sql::v1::SqlInstancesCreateEphemeralCertRequest const&
              request) { return stub_->CreateEphemeral(context, request); },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::RescheduleMaintenance(
    google::cloud::sql::v1::SqlInstancesRescheduleMaintenanceRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->RescheduleMaintenance(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::
                 SqlInstancesRescheduleMaintenanceRequest const& request) {
        return stub_->RescheduleMaintenance(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::SqlInstancesVerifyExternalSyncSettingsResponse>
SqlInstancesServiceConnectionImpl::VerifyExternalSyncSettings(
    google::cloud::sql::v1::SqlInstancesVerifyExternalSyncSettingsRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->VerifyExternalSyncSettings(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::
                 SqlInstancesVerifyExternalSyncSettingsRequest const& request) {
        return stub_->VerifyExternalSyncSettings(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::sql::v1::Operation>
SqlInstancesServiceConnectionImpl::StartExternalSync(
    google::cloud::sql::v1::SqlInstancesStartExternalSyncRequest const&
        request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->StartExternalSync(request),
      [this](grpc::ClientContext& context,
             google::cloud::sql::v1::SqlInstancesStartExternalSyncRequest const&
                 request) {
        return stub_->StartExternalSync(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace sqladmin_internal
}  // namespace cloud
}  // namespace google
