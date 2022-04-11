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
// source: google/cloud/sql/v1/cloud_sql_ssl_certs.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQLADMIN_INTERNAL_SQL_SSL_CERTS_STUB_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQLADMIN_INTERNAL_SQL_SSL_CERTS_STUB_H

#include "google/cloud/status_or.h"
#include "google/cloud/version.h"
#include <google/cloud/sql/v1/cloud_sql_ssl_certs.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace sqladmin_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class SqlSslCertsServiceStub {
 public:
  virtual ~SqlSslCertsServiceStub() = 0;

  virtual StatusOr<google::cloud::sql::v1::Operation> Delete(
      grpc::ClientContext& context,
      google::cloud::sql::v1::SqlSslCertsDeleteRequest const& request) = 0;

  virtual StatusOr<google::cloud::sql::v1::SslCert> Get(
      grpc::ClientContext& context,
      google::cloud::sql::v1::SqlSslCertsGetRequest const& request) = 0;

  virtual StatusOr<google::cloud::sql::v1::SslCertsInsertResponse> Insert(
      grpc::ClientContext& context,
      google::cloud::sql::v1::SqlSslCertsInsertRequest const& request) = 0;

  virtual StatusOr<google::cloud::sql::v1::SslCertsListResponse> List(
      grpc::ClientContext& context,
      google::cloud::sql::v1::SqlSslCertsListRequest const& request) = 0;
};

class DefaultSqlSslCertsServiceStub : public SqlSslCertsServiceStub {
 public:
  explicit DefaultSqlSslCertsServiceStub(
      std::unique_ptr<google::cloud::sql::v1::SqlSslCertsService::StubInterface>
          grpc_stub)
      : grpc_stub_(std::move(grpc_stub)) {}

  StatusOr<google::cloud::sql::v1::Operation> Delete(
      grpc::ClientContext& client_context,
      google::cloud::sql::v1::SqlSslCertsDeleteRequest const& request) override;

  StatusOr<google::cloud::sql::v1::SslCert> Get(
      grpc::ClientContext& client_context,
      google::cloud::sql::v1::SqlSslCertsGetRequest const& request) override;

  StatusOr<google::cloud::sql::v1::SslCertsInsertResponse> Insert(
      grpc::ClientContext& client_context,
      google::cloud::sql::v1::SqlSslCertsInsertRequest const& request) override;

  StatusOr<google::cloud::sql::v1::SslCertsListResponse> List(
      grpc::ClientContext& client_context,
      google::cloud::sql::v1::SqlSslCertsListRequest const& request) override;

 private:
  std::unique_ptr<google::cloud::sql::v1::SqlSslCertsService::StubInterface>
      grpc_stub_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace sqladmin_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQLADMIN_INTERNAL_SQL_SSL_CERTS_STUB_H
