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
// source: google/cloud/dialogflow/cx/v3/agent.proto

#include "google/cloud/dialogflow_cx/agents_client.h"
#include "google/cloud/dialogflow_cx/internal/agents_option_defaults.h"
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_cx {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

AgentsClient::AgentsClient(std::shared_ptr<AgentsConnection> connection,
                           Options opts)
    : connection_(std::move(connection)),
      options_(internal::MergeOptions(
          std::move(opts), dialogflow_cx_internal::AgentsDefaultOptions(
                               connection_->options()))) {}
AgentsClient::~AgentsClient() = default;

StreamRange<google::cloud::dialogflow::cx::v3::Agent> AgentsClient::ListAgents(
    std::string const& parent, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::cx::v3::ListAgentsRequest request;
  request.set_parent(parent);
  return connection_->ListAgents(request);
}

StreamRange<google::cloud::dialogflow::cx::v3::Agent> AgentsClient::ListAgents(
    google::cloud::dialogflow::cx::v3::ListAgentsRequest request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ListAgents(std::move(request));
}

StatusOr<google::cloud::dialogflow::cx::v3::Agent> AgentsClient::GetAgent(
    std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::cx::v3::GetAgentRequest request;
  request.set_name(name);
  return connection_->GetAgent(request);
}

StatusOr<google::cloud::dialogflow::cx::v3::Agent> AgentsClient::GetAgent(
    google::cloud::dialogflow::cx::v3::GetAgentRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetAgent(request);
}

StatusOr<google::cloud::dialogflow::cx::v3::Agent> AgentsClient::CreateAgent(
    std::string const& parent,
    google::cloud::dialogflow::cx::v3::Agent const& agent, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::cx::v3::CreateAgentRequest request;
  request.set_parent(parent);
  *request.mutable_agent() = agent;
  return connection_->CreateAgent(request);
}

StatusOr<google::cloud::dialogflow::cx::v3::Agent> AgentsClient::CreateAgent(
    google::cloud::dialogflow::cx::v3::CreateAgentRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->CreateAgent(request);
}

StatusOr<google::cloud::dialogflow::cx::v3::Agent> AgentsClient::UpdateAgent(
    google::cloud::dialogflow::cx::v3::Agent const& agent,
    google::protobuf::FieldMask const& update_mask, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::cx::v3::UpdateAgentRequest request;
  *request.mutable_agent() = agent;
  *request.mutable_update_mask() = update_mask;
  return connection_->UpdateAgent(request);
}

StatusOr<google::cloud::dialogflow::cx::v3::Agent> AgentsClient::UpdateAgent(
    google::cloud::dialogflow::cx::v3::UpdateAgentRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->UpdateAgent(request);
}

Status AgentsClient::DeleteAgent(std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::cx::v3::DeleteAgentRequest request;
  request.set_name(name);
  return connection_->DeleteAgent(request);
}

Status AgentsClient::DeleteAgent(
    google::cloud::dialogflow::cx::v3::DeleteAgentRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->DeleteAgent(request);
}

future<StatusOr<google::cloud::dialogflow::cx::v3::ExportAgentResponse>>
AgentsClient::ExportAgent(
    google::cloud::dialogflow::cx::v3::ExportAgentRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ExportAgent(request);
}

future<StatusOr<google::protobuf::Struct>> AgentsClient::RestoreAgent(
    google::cloud::dialogflow::cx::v3::RestoreAgentRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->RestoreAgent(request);
}

StatusOr<google::cloud::dialogflow::cx::v3::AgentValidationResult>
AgentsClient::ValidateAgent(
    google::cloud::dialogflow::cx::v3::ValidateAgentRequest const& request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->ValidateAgent(request);
}

StatusOr<google::cloud::dialogflow::cx::v3::AgentValidationResult>
AgentsClient::GetAgentValidationResult(std::string const& name, Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  google::cloud::dialogflow::cx::v3::GetAgentValidationResultRequest request;
  request.set_name(name);
  return connection_->GetAgentValidationResult(request);
}

StatusOr<google::cloud::dialogflow::cx::v3::AgentValidationResult>
AgentsClient::GetAgentValidationResult(
    google::cloud::dialogflow::cx::v3::GetAgentValidationResultRequest const&
        request,
    Options opts) {
  internal::OptionsSpan span(internal::MergeOptions(std::move(opts), options_));
  return connection_->GetAgentValidationResult(request);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx
}  // namespace cloud
}  // namespace google
