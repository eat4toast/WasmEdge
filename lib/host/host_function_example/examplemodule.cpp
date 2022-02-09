// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#include "host/host_function_example/examplemodule.h"

#include "host/host_function_example/examplefunc.h"

namespace WasmEdge {
namespace Host {

/// Register your functions in module.
HostFuncExampleModule::HostFuncExampleModule()
    : ImportObject("host_function_example") {
  addHostFunc("host_function_example_set_class_id",
              std::make_unique<HostFuncExampleSetClassID>(Env));
  addHostFunc("host_function_example_add_student",
              std::make_unique<HostFuncExampleAddStudent>(Env));
  addHostFunc("host_function_example_set_class_name",
              std::make_unique<HostFuncExampleSetClassName>(Env));
  addHostFunc("host_function_example_print",
              std::make_unique<HostFuncExamplePrint>(Env));
}

} // namespace Host
} // namespace WasmEdge
