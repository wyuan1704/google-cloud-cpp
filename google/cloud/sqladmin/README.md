# Cloud SQL Admin API C++ Client Library

:construction:

This directory contains an idiomatic C++ client library for the
[Cloud SQL Admin API][cloud-service-docs], a service for Cloud SQL database
instance management.

This library is **experimental**. Its APIs are subject to change without notice.

Please note that the Google Cloud C++ client libraries do **not** follow
[Semantic Versioning](https://semver.org/).

## Supported Platforms

* Windows, macOS, Linux
* C++11 (and higher) compilers (we test with GCC >= 5.4, Clang >= 6.0, and
  MSVC >= 2017)
* Environments with or without exceptions
* Bazel and CMake builds

## Documentation

* Official documentation about the [Cloud SQL Admin API][cloud-service-docs] service
* [Reference doxygen documentation][doxygen-link] for each release of this
  client library
* Detailed header comments in our [public `.h`][source-link] files

[cloud-service-docs]: https://cloud.google.com/sql
[doxygen-link]: https://googleapis.dev/cpp/google-cloud-sqladmin/latest/
[source-link]: https://github.com/googleapis/google-cloud-cpp/tree/main/google/cloud/sqladmin

## Quickstart

The [quickstart/](quickstart/README.md) directory contains a minimal environment
to get started using this client library in a larger project. The following
"Hello World" program is used in this quickstart, and should give you a taste of
this library.

<!-- inject-quickstart-start -->
```cc
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
  request.set_project(project.FullName());
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
```
<!-- inject-quickstart-end -->

* Packaging maintainers or developers who prefer to install the library in a
  fixed directory (such as `/usr/local` or `/opt`) should consult the
  [packaging guide](/doc/packaging.md).
* Developers wanting to use the libraries as part of a larger CMake or Bazel
  project should consult the [quickstart guides](#quickstart) for the library
  or libraries they want to use.
* Developers wanting to compile the library just to run some of the examples or
  tests should read the current document.
* Contributors and developers to `google-cloud-cpp` should consult the guide to
  [setup a development workstation][howto-setup-dev-workstation].

[howto-setup-dev-workstation]: /doc/contributor/howto-guide-setup-development-workstation.md

## Contributing changes

See [`CONTRIBUTING.md`](../../../CONTRIBUTING.md) for details on how to
contribute to this project, including how to build and test your changes
as well as how to properly format your code.

## Licensing

Apache 2.0; see [`LICENSE`](../../../LICENSE) for details.
