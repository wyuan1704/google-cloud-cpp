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
// source: google/cloud/sql/v1/cloud_sql_connect.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQLADMIN_INTERNAL_SQL_CONNECT_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQLADMIN_INTERNAL_SQL_CONNECT_STUB_H

#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/sql/v1/cloud_sql_connect.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace sqladmin_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class SqlConnectServiceStub {
 public:
  virtual ~SqlConnectServiceStub() = 0;

  virtual StatusOr<google::cloud::sql::v1::ConnectSettings> GetConnectSettings(
      grpc::ClientContext& context,
      google::cloud::sql::v1::GetConnectSettingsRequest const& request) = 0;

  virtual StatusOr<google::cloud::sql::v1::GenerateEphemeralCertResponse>
  GenerateEphemeralCert(
      grpc::ClientContext& context,
      google::cloud::sql::v1::GenerateEphemeralCertRequest const& request) = 0;
};

class DefaultSqlConnectServiceStub : public SqlConnectServiceStub {
 public:
  explicit DefaultSqlConnectServiceStub(
      std::unique_ptr<google::cloud::sql::v1::SqlConnectService::StubInterface>
          grpc_stub)
      : grpc_stub_(std::move(grpc_stub)) {}

  StatusOr<google::cloud::sql::v1::ConnectSettings> GetConnectSettings(
      grpc::ClientContext& client_context,
      google::cloud::sql::v1::GetConnectSettingsRequest const& request)
      override;

  StatusOr<google::cloud::sql::v1::GenerateEphemeralCertResponse>
  GenerateEphemeralCert(
      grpc::ClientContext& client_context,
      google::cloud::sql::v1::GenerateEphemeralCertRequest const& request)
      override;

 private:
  std::unique_ptr<google::cloud::sql::v1::SqlConnectService::StubInterface>
      grpc_stub_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace sqladmin_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQLADMIN_INTERNAL_SQL_CONNECT_STUB_H
