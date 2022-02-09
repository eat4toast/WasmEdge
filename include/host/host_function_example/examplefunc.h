// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#pragma once

#include "common/defines.h"
#include "host/host_function_example/examplebase.h"

namespace WasmEdge {
namespace Host {

class HostFuncExampleSetClassID
    : public HostFuncExample<HostFuncExampleSetClassID> {
public:
  HostFuncExampleSetClassID(HostFuncExampleEnvironment &HostEnv)
      : HostFuncExample(HostEnv) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst,
                    uint32_t CID);
};

class HostFuncExampleAddStudent : public HostFuncExample<HostFuncExampleAddStudent> {
public:
  HostFuncExampleAddStudent(HostFuncExampleEnvironment &HostEnv)
      : HostFuncExample(HostEnv) {}
  Expect<uint32_t> body(Runtime::Instance::MemoryInstance *MemInst, uint32_t StudentPtr,
                    uint32_t StudentLen);
};

class HostFuncExampleSetClassName : public HostFuncExample<HostFuncExampleSetClassName> {
public:
  HostFuncExampleSetClassName(HostFuncExampleEnvironment &HostEnv)
      : HostFuncExample(HostEnv) {}
  Expect<void> body(Runtime::Instance::MemoryInstance *MemInst, uint32_t ClassNamePtr,
                    uint32_t ClassNameLen);
};

class HostFuncExamplePrint : public HostFuncExample<HostFuncExamplePrint> {
public:
  HostFuncExamplePrint(HostFuncExampleEnvironment &HostEnv)
      : HostFuncExample(HostEnv) {}
  Expect<void> body(Printtime::Instance::MemoryInstance *MemInst);
};

} // namespace Host
} // namespace WasmEdge
