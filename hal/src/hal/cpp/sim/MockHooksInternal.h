#pragma once

#include <stdint.h>

#include "MockData/MockHooks.h"

namespace hal {
void RestartTiming();

int64_t GetFPGATime();

double GetFPGATimestamp();

void SetProgramStarted();
}
