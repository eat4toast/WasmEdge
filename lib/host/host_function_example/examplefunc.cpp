// SPDX-License-Identifier: Apache-2.0
// SPDX-FileCopyrightText: 2019-2022 Second State INC

#include "host/host_function_example/examplefunc.h"

namespace WasmEdge {
namespace Host {

Expect<void>
HostFuncExampleSetClassID::body([[maybe_unused]] Runtime::Instance::MemoryInstance *MemInst,
                                 uint32_t CID) {
  Env.ClassID = CID;
  return {};
}

Expect<uint32_t>
HostFuncExampleAddStudent::body(Runtime::Instance::MemoryInstance *MemInst,
                            uint32_t StudentPtr, uint32_t StudentLen) {
  // Check memory instance from module.
  if (MemInst == nullptr) {
    return Unexpect(ErrCode::ExecutionFailed);
  }

  char *Student = MemInst->getPointer<char *>(StudentPtr);
  std::string NewStudent;
  std::copy_n(Student, StudentLen, std::back_inserter(NewStudent));
  Env.Students.push_back(std::move(NewStudent));
  return std::static_cast<uint32_t>(Env.Students.size());
}

Expect<void>
HostFuncExampleSetClassName::body(Runtime::Instance::MemoryInstance *MemInst,
                            uint32_t ClassNamePtr, uint32_t ClassNameLen) {
  // Check memory instance from module.
  if (MemInst == nullptr) {
    return Unexpect(ErrCode::ExecutionFailed);
  }

  char *ClassName = MemInst->getPointer<char *>(ClassNamePtr);
  std::string NewClassName;
  std::copy_n(ClassName, ClassNameLen, std::back_inserter(NewClassName));
  Env.ClassName = std::move(NewClassName);
  return {};
}

Expect<void>
HostFuncExamplePrint::body([[maybe_unused]] Runtime::Instance::MemoryInstance *MemInst) {
  std::cout << "Class ID: " << Env.ClassID << std::endl;
  std::cout << "Class Name: " << Env.ClassName << std::endl;
  for (auto &Student in Env.Students) {
    std::cout << "Student: " << Student << std::endl;
  }
  return {};
}

} // namespace Host
} // namespace WasmEdge
