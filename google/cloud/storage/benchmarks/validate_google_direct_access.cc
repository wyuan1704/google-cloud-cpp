// Copyright 2020 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#if GOOGLE_CLOUD_CPP_STORAGE_HAVE_GRPC
#include "google/cloud/storage/grpc_plugin.h"
#include "google/cloud/storage/internal/grpc_client.h"
#include "google/cloud/storage/internal/storage_stub_factory.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/testing_util/command_line_parsing.h"
#include <google/storage/v2/storage.grpc.pb.h>
#include <sstream>
#include <string>
#include <vector>

namespace {
struct DirectAccessOptions {
  std::string bucket_name;
  std::string object_name;
  std::string grpc_endpoint = "storage.googleapis.com";
};

DirectAccessOptions ParseCommandLine(std::vector<std::string> argv);
}  // namespace

namespace gcs = ::google::cloud::storage;
namespace g = ::google::cloud;
namespace v2 = ::google::storage::v2;

void TestWithGrpc(DirectAccessOptions const& options) {
  // Use gRPC to read an object, without any fancy wrappers.
  grpc::ChannelArguments args;
  auto channel = grpc::CreateChannel(options.grpc_endpoint,
                                     grpc::GoogleDefaultCredentials());
  auto stub = google::storage::v2::Storage::NewStub(std::move(channel));
  grpc::ClientContext context;
  v2::ReadObjectRequest request;
  request.set_bucket("projects/_/buckets/" + options.bucket_name);
  request.set_object(options.object_name);
  auto reader = stub->ReadObject(&context, request);
  while (true) {
    v2::ReadObjectResponse response;
    auto success = reader->Read(&response);
    if (!success) {
      auto status = reader->Finish();
      std::cout << "stream status=" << g::MakeStatusFromRpcError(status)
                << "\n";
      break;
    }
    if (response.has_metadata()) {
      std::cout << "Object metadata=" << response.metadata().DebugString()
                << "\n";
    }
  }
  std::cout << "Call initial metadata\n";
  std::cout << "peer: " << context.peer() << "\n";
  for (auto const& kv : context.GetServerInitialMetadata()) {
    std::cout << kv.first << ": " << kv.second << "\n";
  }
  std::cout << "Call trailing metadata\n";
  for (auto const& kv : context.GetServerTrailingMetadata()) {
    std::cout << kv.first << ": " << kv.second << "\n";
  }
}

void TestWithWrappedGrpc(DirectAccessOptions const& options) {
  // Use the lowest layer of wrappers in the C++ client library to read an
  // object. This is not intended for use by customers, it is here just for
  // troubleshooting.
  g::CompletionQueue cq;
  auto stub = google::cloud::storage_internal::CreateStorageStub(
      cq, google::cloud::storage::internal::DefaultOptionsGrpc(
              g::Options{}
                  .set<g::TracingComponentsOption>({"rpc", "rpc-streams"})
                  .set<g::UnifiedCredentialsOption>(
                      g::MakeGoogleDefaultCredentials())
                  .set<g::EndpointOption>(options.grpc_endpoint)));

  v2::ReadObjectRequest request;
  request.set_bucket("projects/_/buckets/" + options.bucket_name);
  request.set_object(options.object_name);
  auto context = absl::make_unique<grpc::ClientContext>();
  auto stream = stub->ReadObject(std::move(context), request);
  v2::Object grpc_metadata;
  while (true) {
    auto v = stream->Read();
    if (absl::holds_alternative<g::Status>(v)) {
      std::cout << "stream status=" << absl::get<g::Status>(v) << "\n";
      break;
    }
    auto value = absl::get<v2::ReadObjectResponse>(std::move(v));
    if (value.has_metadata()) {
      std::cout << "Object metadata=" << value.metadata().DebugString() << "\n";
    }
  }

  std::cout << "Call metadata\n";
  for (auto const& kv : stream->GetRequestMetadata()) {
    std::cout << kv.first << ": " << kv.second << "\n";
  }
}

void TestWithClientLibrary(DirectAccessOptions const& options) {
  // Use the client library to read an object. This is not intended for use by
  // customers, it is here just for troubleshooting.
  auto client = google::cloud::storage_experimental::DefaultGrpcClient(
      g::Options{}
          .set<g::TracingComponentsOption>({"rpc", "rpc-streams"})
          .set<g::UnifiedCredentialsOption>(g::MakeGoogleDefaultCredentials())
          .set<g::EndpointOption>(options.grpc_endpoint));

  auto stream = client.ReadObject(options.bucket_name, options.object_name);
  auto contents = std::string{std::istreambuf_iterator<char>(stream), {}};
  std::cout << "stream status=" << stream.status() << "\n";

  std::cout << "Object metadata="
            << "generation=" << stream.generation().value_or(0)
            << ", metageneration=" << stream.metageneration().value_or(0)
            << ", storage_class=" << stream.storage_class().value_or("unknown")
            << "\n";

  std::cout << "Call 'headers'\n";
  for (auto const& kv : stream.headers()) {
    std::cout << kv.first << ": " << kv.second << "\n";
  }
}

int main(int argc, char* argv[]) try {
  auto const options = ParseCommandLine({argv, argv + argc});

  std::cout << "Use REST to verify the object exists\n";
  auto client =
      gcs::Client(g::Options{}.set<g::TracingComponentsOption>({"raw-client"}));
  auto metadata =
      client.GetObjectMetadata(options.bucket_name, options.object_name)
          .value();
  std::cout << "REST response=" << metadata << "\n";

  std::cout << "Starting gRPC test\n";
  TestWithGrpc(options);
  std::cout << "gRPC test DONE\n";

  std::cout << "\n\n\nStarting Wrapped gRPC test\n";
  TestWithWrappedGrpc(options);
  std::cout << "Wrapped gRPC test DONE\n";

  std::cout << "\n\n\nStarting C++ client library test\n";
  TestWithClientLibrary(options);
  std::cout << "Wrapped gRPC test DONE\n";

  return 0;
} catch (std::exception const& ex) {
  std::cerr << "Standard C++ exception raised: " << ex.what() << std::endl;
}

namespace {
DirectAccessOptions ParseCommandLine(std::vector<std::string> argv) {
  using ::google::cloud::testing_util::OptionDescriptor;

  DirectAccessOptions options;
  std::vector<OptionDescriptor> desc{
      {"--bucket-name", "use the given bucket to run the test",
       [&options](std::string const& val) { options.bucket_name = val; }},
      {"--object-name", "use the given object to run the test",
       [&options](std::string const& val) { options.object_name = val; }},
      {"--grpc-endpoint", "change the default endpoint",
       [&options](std::string const& val) { options.grpc_endpoint = val; }},
  };
  auto usage = BuildUsage(desc, argv[0]);

  auto const unparsed = OptionsParse(desc, argv);
  if (unparsed.size() > 2) {
    std::ostringstream os;
    os << "Unknown arguments or options: ";
    std::copy(unparsed.begin(), unparsed.end(),
              std::ostream_iterator<std::string>(os, " "));
    os << usage;
    throw std::runtime_error(std::move(os).str());
  }

  return options;
}

}  // namespace

#endif  // GOOGLE_CLOUD_CPP_STORAGE_HAVE_GRPC
