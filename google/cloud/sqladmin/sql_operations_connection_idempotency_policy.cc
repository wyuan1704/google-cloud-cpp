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
// source: google/cloud/sql/v1/cloud_sql_operations.proto

#include "google/cloud/sqladmin/sql_operations_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace sqladmin {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

SqlOperationsServiceConnectionIdempotencyPolicy::
    ~SqlOperationsServiceConnectionIdempotencyPolicy() = default;

namespace {
class DefaultSqlOperationsServiceConnectionIdempotencyPolicy
    : public SqlOperationsServiceConnectionIdempotencyPolicy {
 public:
  ~DefaultSqlOperationsServiceConnectionIdempotencyPolicy() override = default;

  /// Create a new copy of this object.
  std::unique_ptr<SqlOperationsServiceConnectionIdempotencyPolicy> clone()
      const override {
    return absl::make_unique<
        DefaultSqlOperationsServiceConnectionIdempotencyPolicy>(*this);
  }

  Idempotency Get(
      google::cloud::sql::v1::SqlOperationsGetRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency List(
      google::cloud::sql::v1::SqlOperationsListRequest const&) override {
    return Idempotency::kIdempotent;
  }
};
}  // namespace

std::unique_ptr<SqlOperationsServiceConnectionIdempotencyPolicy>
MakeDefaultSqlOperationsServiceConnectionIdempotencyPolicy() {
  return absl::make_unique<
      DefaultSqlOperationsServiceConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace sqladmin
}  // namespace cloud
}  // namespace google
