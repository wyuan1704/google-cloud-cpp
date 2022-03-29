# Copyright 2022 Google LLC
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

load("@rules_cc//cc:toolchain_utils.bzl", "find_cpp_toolchain")

def _capture_build_info_impl(ctx):
    cc_toolchain = find_cpp_toolchain(ctx)
    ctx.actions.expand_template(
        template = ctx.file.template,
        output = ctx.outputs.source_file,
        substitutions = {
            "@CMAKE_CXX_FLAGS@": str(cc_toolchain),
            "${CMAKE_CXX_FLAGS_${GOOGLE_CLOUD_CPP_BUILD_TYPE_UPPER}}": "",
            "@GOOGLE_CLOUD_CPP_BUILD_METADATA@": "\n".join(dir(cc_toolchain)),
        },
    )

capture_build_info = rule(
    implementation = _capture_build_info_impl,
    attrs = {
        "template": attr.label(
            allow_single_file = True,
            mandatory = True,
        ),
        "source_file": attr.output(mandatory = True),
        "_cc_toolchain": attr.label(default = Label("@bazel_tools//tools/cpp:current_cc_toolchain")),
    },
    toolchains = ["@bazel_tools//tools/cpp:toolchain_type"]
)
