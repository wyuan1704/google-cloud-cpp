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
#include "google/cloud/storage/client.h"
#include "google/cloud/storage/internal/grpc_client.h"
#include "google/cloud/storage/internal/storage_stub_factory.h"
#include "google/cloud/testing_util/command_line_parsing.h"
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

int main(int argc, char* argv[]) try {
  auto const options = ParseCommandLine({argv, argv + argc});

  std::cout << "Use REST to verify the object exists\n";
  auto client =
      gcs::Client(g::Options{}.set<g::TracingComponentsOption>({"raw-client"}));
  auto metadata =
      client.GetObjectMetadata(options.bucket_name, options.object_name)
          .value();
  std::cout << "REST response=" << metadata << "\n";

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
      std::cout << "gRPC metadata=" << value.metadata().DebugString() << "\n";
    }
  }

  std::cout << "gRPC call metadata\n";
  for (auto const& kv : stream->GetRequestMetadata()) {
    std::cout << kv.first << ": " << kv.second << "\n";
  }

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
