// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUBLITE_TESTING_MOCK_BACKOFF_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUBLITE_TESTING_MOCK_BACKOFF_POLICY_H

#include "google/cloud/backoff_policy.h"
#include "google/cloud/version.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace pubsublite_testing {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class MockBackoffPolicy : public google::cloud::internal::BackoffPolicy {
 public:
  MOCK_METHOD(std::unique_ptr<BackoffPolicy>, clone, (), (const override));
  MOCK_METHOD(std::chrono::milliseconds, OnCompletion, (), (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsublite_testing
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_PUBSUBLITE_TESTING_MOCK_BACKOFF_POLICY_H
