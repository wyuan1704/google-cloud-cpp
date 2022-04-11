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
// source: google/cloud/sql/v1/cloud_sql_users.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQLADMIN_SQL_USERS_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQLADMIN_SQL_USERS_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/version.h"
#include <google/cloud/sql/v1/cloud_sql_users.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace sqladmin {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class SqlUsersServiceConnectionIdempotencyPolicy {
 public:
  virtual ~SqlUsersServiceConnectionIdempotencyPolicy() = 0;

  /// Create a new copy of this object.
  virtual std::unique_ptr<SqlUsersServiceConnectionIdempotencyPolicy> clone()
      const = 0;

  virtual google::cloud::Idempotency Delete(
      google::cloud::sql::v1::SqlUsersDeleteRequest const& request) = 0;

  virtual google::cloud::Idempotency Insert(
      google::cloud::sql::v1::SqlUsersInsertRequest const& request) = 0;

  virtual google::cloud::Idempotency List(
      google::cloud::sql::v1::SqlUsersListRequest const& request) = 0;

  virtual google::cloud::Idempotency Update(
      google::cloud::sql::v1::SqlUsersUpdateRequest const& request) = 0;
};

std::unique_ptr<SqlUsersServiceConnectionIdempotencyPolicy>
MakeDefaultSqlUsersServiceConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace sqladmin
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQLADMIN_SQL_USERS_CONNECTION_IDEMPOTENCY_POLICY_H
