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
// source: google/cloud/dialogflow/v2/knowledge_base.proto

#include "google/cloud/dialogflow_es/knowledge_bases_connection.h"
#include "google/cloud/dialogflow_es/internal/knowledge_bases_connection_impl.h"
#include "google/cloud/dialogflow_es/internal/knowledge_bases_option_defaults.h"
#include "google/cloud/dialogflow_es/internal/knowledge_bases_stub_factory.h"
#include "google/cloud/dialogflow_es/knowledge_bases_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

KnowledgeBasesConnection::~KnowledgeBasesConnection() = default;

StreamRange<google::cloud::dialogflow::v2::KnowledgeBase>
KnowledgeBasesConnection::ListKnowledgeBases(
    google::cloud::dialogflow::v2::
        ListKnowledgeBasesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::dialogflow::v2::KnowledgeBase>>();
}

StatusOr<google::cloud::dialogflow::v2::KnowledgeBase>
KnowledgeBasesConnection::GetKnowledgeBase(
    google::cloud::dialogflow::v2::GetKnowledgeBaseRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::dialogflow::v2::KnowledgeBase>
KnowledgeBasesConnection::CreateKnowledgeBase(
    google::cloud::dialogflow::v2::CreateKnowledgeBaseRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status KnowledgeBasesConnection::DeleteKnowledgeBase(
    google::cloud::dialogflow::v2::DeleteKnowledgeBaseRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::dialogflow::v2::KnowledgeBase>
KnowledgeBasesConnection::UpdateKnowledgeBase(
    google::cloud::dialogflow::v2::UpdateKnowledgeBaseRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<KnowledgeBasesConnection> MakeKnowledgeBasesConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 KnowledgeBasesPolicyOptionList>(options,
                                                                 __func__);
  options =
      dialogflow_es_internal::KnowledgeBasesDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = dialogflow_es_internal::CreateDefaultKnowledgeBasesStub(
      background->cq(), options);
  return std::make_shared<dialogflow_es_internal::KnowledgeBasesConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es
}  // namespace cloud
}  // namespace google

namespace google {
namespace cloud {
namespace dialogflow_es_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

std::shared_ptr<dialogflow_es::KnowledgeBasesConnection>
MakeKnowledgeBasesConnection(std::shared_ptr<KnowledgeBasesStub> stub,
                             Options options) {
  options = KnowledgeBasesDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  return std::make_shared<dialogflow_es_internal::KnowledgeBasesConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es_internal
}  // namespace cloud
}  // namespace google
