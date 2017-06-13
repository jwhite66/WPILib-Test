#include "HAL/Notifier.h"
#include "HAL/HAL.h"

#include <iostream>
#include <chrono>
#include <string>
#include <thread>

uint64_t lastTime = 0;

int main() {

  HAL_Initialize(0);
  int32_t status = 0;
  
  auto handle = HAL_InitializeNotifier([](uint64_t time, HAL_NotifierHandle handle){
    auto delta = (time - lastTime) * 1.0e-6;
    lastTime = time;
    std::cout << delta << std::endl;
    int32_t s = 0;
    HAL_UpdateNotifierAlarm(handle, time + 500000, &s);
  }, nullptr, &status);

  status = 0;
  lastTime = HAL_GetFPGATime(&status);
  HAL_UpdateNotifierAlarm(handle, lastTime + 500000, &status);

  bool running = true;
  std::string val = "";
  while(true) {
     std::cin >> val;
     if (running) {
       HAL_CleanNotifier(handle, &status);
       running = false;
     } 
  }

}