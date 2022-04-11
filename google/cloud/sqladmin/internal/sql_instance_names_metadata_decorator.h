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
// source: google/cloud/sql/v1/cloud_sql_instance_names.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQLADMIN_INTERNAL_SQL_INSTANCE_NAMES_METADATA_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQLADMIN_INTERNAL_SQL_INSTANCE_NAMES_METADATA_DECORATOR_H

#include "google/cloud/sqladmin/internal/sql_instance_names_stub.h"
#include "google/cloud/version.h"
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace sqladmin_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class SqlInstanceNamesServiceMetadata : public SqlInstanceNamesServiceStub {
 public:
  ~SqlInstanceNamesServiceMetadata() override = default;
  explicit SqlInstanceNamesServiceMetadata(
      std::shared_ptr<SqlInstanceNamesServiceStub> child);

 private:
  void SetMetadata(grpc::ClientContext& context,
                   std::string const& request_params);
  void SetMetadata(grpc::ClientContext& context);

  std::shared_ptr<SqlInstanceNamesServiceStub> child_;
  std::string api_client_header_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace sqladmin_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SQLADMIN_INTERNAL_SQL_INSTANCE_NAMES_METADATA_DECORATOR_H
