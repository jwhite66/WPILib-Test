#pragma once

namespace hal {
  HAL_NotifierHandle initializeNotifierNonThreaded(HAL_NotifierProcessFunction process, void* param, int32_t* status);
}  // namespace hal
