// Copyright 2022 Google LLC
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

#include "google/cloud/sqladmin/sql_instances_client.h"
#include "google/cloud/project.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) try {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " project-id\n";
    return 1;
  }

  namespace sqladmin = ::google::cloud::sqladmin;
  auto client = sqladmin::SqlInstancesServiceClient(
      sqladmin::MakeSqlInstancesServiceConnection());

  auto const project = google::cloud::Project(argv[1]);
  google::cloud::sql::v1::SqlInstancesListRequest request;
  request.set_project(argv[1]); // project.FullName());
  auto page_token = std::string{};
  while (true) {
    request.set_page_token(page_token);
    auto response = client.List(request);
    if (!response) throw std::runtime_error(response.status().message());
    for (auto const& w : response->warnings()) {
      std::cout << "warning: " << w.DebugString() << "\n";
    }
    for (auto const& instance : response->items()) {
      std::cout << instance.DebugString() << "\n";
    }
    if (response->next_page_token().empty()) break;
    page_token = response->next_page_token();
  }

  return 0;
} catch (std::exception const& ex) {
  std::cerr << "Standard exception raised: " << ex.what() << "\n";
  return 1;
}
