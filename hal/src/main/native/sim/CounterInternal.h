#pragma once

#include "HAL/handles/HandlesInternal.h"
#include "HAL/handles/LimitedHandleResource.h"
#include "PortsInternal.h"


namespace hal {

struct Counter{
  uint8_t index;
};

extern LimitedHandleResource<HAL_CounterHandle, Counter,
                             kNumCounters, HAL_HandleEnum::Counter>
    counterHandles;

} // namespace HAL