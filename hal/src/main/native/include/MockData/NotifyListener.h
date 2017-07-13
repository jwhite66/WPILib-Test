#pragma once

#include "HAL_Value.h"

typedef void (*HAL_NotifyCallback)(const char* name, void* param, const struct HAL_Value *value);

namespace hal {
struct NotifyListener {
    NotifyListener() = default;
    NotifyListener(void* param_, HAL_NotifyCallback callback_) 
    : callback(callback_), param(param_) {}

    explicit operator bool() const { return bool(callback); }

    HAL_NotifyCallback callback;
    void* param;
  };
}