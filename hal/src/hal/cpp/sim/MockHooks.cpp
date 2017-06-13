#include "MockHooksInternal.h"

#include <chrono>
#include <atomic>
#include <cstdio>
#include <thread>
#include "support/timestamp.h"

static std::atomic<bool> programStarted {false};

static std::atomic<uint64_t> programStartTime {wpi::Now() / 10};

namespace hal {
void RestartTiming() {
  programStartTime = wpi::Now() / 10;
}

int64_t GetFPGATime() {
  auto now = wpi::Now() / 10;
  auto currentTime = now - programStartTime;
  return currentTime;
}

double GetFPGATimestamp() {
  auto now = wpi::Now() / 10;
  auto currentTime = now - programStartTime;
  return currentTime * 1.0e-6;
}

void SetProgramStarted() {
  programStarted = true;
}
}

using namespace hal;

extern "C" {
void HALSIM_WaitForProgramStart(void) {
  int count = 0;
  while (!programStarted) {
    count++;
    std::printf("Waiting for program start signal: %d\n", count);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
  }
}

void HALSIM_SetProgramStarted(void) {
  SetProgramStarted();
}

void HALSIM_RestartTiming(void) {
  RestartTiming();
}
}