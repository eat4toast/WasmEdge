// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#pragma once

#include "common/errcode.h"
#include "host/host_function_example/exampleenv.h"
#include "runtime/hostfunc.h"

namespace WasmEdge {
namespace Host {

template <typename T> class HostFuncExample : public Runtime::HostFunction<T> {
public:
  HostFuncExample(HostFuncExampleEnvironment &HostEnv)
      : Runtime::HostFunction<T>(0), Env(HostEnv) {}

protected:
  HostFuncExampleEnvironment &Env;
};

} // namespace Host
} // namespace WasmEdge
