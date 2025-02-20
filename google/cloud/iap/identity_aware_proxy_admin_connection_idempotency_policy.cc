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
// source: google/cloud/iap/v1/service.proto

#include "google/cloud/iap/identity_aware_proxy_admin_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace iap {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

IdentityAwareProxyAdminServiceConnectionIdempotencyPolicy::
    ~IdentityAwareProxyAdminServiceConnectionIdempotencyPolicy() = default;

namespace {
class DefaultIdentityAwareProxyAdminServiceConnectionIdempotencyPolicy
    : public IdentityAwareProxyAdminServiceConnectionIdempotencyPolicy {
 public:
  ~DefaultIdentityAwareProxyAdminServiceConnectionIdempotencyPolicy() override =
      default;

  /// Create a new copy of this object.
  std::unique_ptr<IdentityAwareProxyAdminServiceConnectionIdempotencyPolicy>
  clone() const override {
    return absl::make_unique<
        DefaultIdentityAwareProxyAdminServiceConnectionIdempotencyPolicy>(
        *this);
  }

  Idempotency SetIamPolicy(
      google::iam::v1::SetIamPolicyRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency GetIamPolicy(
      google::iam::v1::GetIamPolicyRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency TestIamPermissions(
      google::iam::v1::TestIamPermissionsRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency GetIapSettings(
      google::cloud::iap::v1::GetIapSettingsRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency UpdateIapSettings(
      google::cloud::iap::v1::UpdateIapSettingsRequest const&) override {
    return Idempotency::kNonIdempotent;
  }
};
}  // namespace

std::unique_ptr<IdentityAwareProxyAdminServiceConnectionIdempotencyPolicy>
MakeDefaultIdentityAwareProxyAdminServiceConnectionIdempotencyPolicy() {
  return absl::make_unique<
      DefaultIdentityAwareProxyAdminServiceConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace iap
}  // namespace cloud
}  // namespace google
