#pragma once

#include <memory>
#include <string>

#include "MockData/llvm/StringRef.h"
#include "MockData/HALValue.h"

namespace hal {

class Value;

void ConvertToC(const Value& in, HAL_Value* out);
std::shared_ptr<Value> ConvertFromC(const HAL_Value& value);
void ConvertToC(llvm::StringRef in, HALString* out);
inline llvm::StringRef ConvertFromC(const HALString& str) {
  return llvm::StringRef(str.str, str.len);
}

}  // namespace hal