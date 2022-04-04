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
// source: google/cloud/retail/v2/product_service.proto

#include "google/cloud/retail/internal/product_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/retail/v2/product_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace retail_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

ProductServiceLogging::ProductServiceLogging(
    std::shared_ptr<ProductServiceStub> child, TracingOptions tracing_options,
    std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::retail::v2::Product>
ProductServiceLogging::CreateProduct(
    grpc::ClientContext& context,
    google::cloud::retail::v2::CreateProductRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::retail::v2::CreateProductRequest const& request) {
        return child_->CreateProduct(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::retail::v2::Product> ProductServiceLogging::GetProduct(
    grpc::ClientContext& context,
    google::cloud::retail::v2::GetProductRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::retail::v2::GetProductRequest const& request) {
        return child_->GetProduct(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::retail::v2::ListProductsResponse>
ProductServiceLogging::ListProducts(
    grpc::ClientContext& context,
    google::cloud::retail::v2::ListProductsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::retail::v2::ListProductsRequest const& request) {
        return child_->ListProducts(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::retail::v2::Product>
ProductServiceLogging::UpdateProduct(
    grpc::ClientContext& context,
    google::cloud::retail::v2::UpdateProductRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::retail::v2::UpdateProductRequest const& request) {
        return child_->UpdateProduct(context, request);
      },
      context, request, __func__, tracing_options_);
}

Status ProductServiceLogging::DeleteProduct(
    grpc::ClientContext& context,
    google::cloud::retail::v2::DeleteProductRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::retail::v2::DeleteProductRequest const& request) {
        return child_->DeleteProduct(context, request);
      },
      context, request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ProductServiceLogging::AsyncImportProducts(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::retail::v2::ImportProductsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::retail::v2::ImportProductsRequest const& request) {
        return child_->AsyncImportProducts(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ProductServiceLogging::AsyncSetInventory(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::retail::v2::SetInventoryRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::retail::v2::SetInventoryRequest const& request) {
        return child_->AsyncSetInventory(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ProductServiceLogging::AsyncAddFulfillmentPlaces(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::retail::v2::AddFulfillmentPlacesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::retail::v2::AddFulfillmentPlacesRequest const&
                 request) {
        return child_->AsyncAddFulfillmentPlaces(cq, std::move(context),
                                                 request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ProductServiceLogging::AsyncRemoveFulfillmentPlaces(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::retail::v2::RemoveFulfillmentPlacesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::retail::v2::RemoveFulfillmentPlacesRequest const&
                 request) {
        return child_->AsyncRemoveFulfillmentPlaces(cq, std::move(context),
                                                    request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ProductServiceLogging::AsyncAddLocalInventories(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::retail::v2::AddLocalInventoriesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::retail::v2::AddLocalInventoriesRequest const&
                 request) {
        return child_->AsyncAddLocalInventories(cq, std::move(context),
                                                request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ProductServiceLogging::AsyncRemoveLocalInventories(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::retail::v2::RemoveLocalInventoriesRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::retail::v2::RemoveLocalInventoriesRequest const&
                 request) {
        return child_->AsyncRemoveLocalInventories(cq, std::move(context),
                                                   request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<StatusOr<google::longrunning::Operation>>
ProductServiceLogging::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return child_->AsyncGetOperation(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

future<Status> ProductServiceLogging::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return child_->AsyncCancelOperation(cq, std::move(context), request);
      },
      cq, std::move(context), request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace retail_internal
}  // namespace cloud
}  // namespace google
