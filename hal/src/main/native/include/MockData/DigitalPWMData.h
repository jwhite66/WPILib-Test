#pragma once

#include "HAL/HAL.h"
#include "NotifyListener.h"

#ifdef __cplusplus
extern "C" {
#endif

void HALSIM_ResetDigitalPWMData(int32_t index);
int32_t HALSIM_RegisterDigitalPWMInitializedCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelDigitalPWMInitializedCallback(int32_t index, int32_t uid);
HAL_Bool HALSIM_GetDigitalPWMInitialized(int32_t index);
void HALSIM_SetDigitalPWMInitialized(int32_t index, HAL_Bool initialized);

int32_t HALSIM_RegisterDigitalPWMDutyCycleCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelDigitalPWMDutyCycleCallback(int32_t index, int32_t uid);
double HALSIM_GetDigitalPWMDutyCycle(int32_t index);
void HALSIM_SetDigitalPWMDutyCycle(int32_t index, double dutyCycle);

int32_t HALSIM_RegisterDigitalPWMPinCallback(int32_t index, HAL_NotifyCallback callback, void* param, HAL_Bool initialNotify);
void HALSIM_CancelDigitalPWMPinCallback(int32_t index, int32_t uid);
int32_t HALSIM_GetDigitalPWMPin(int32_t index);
void HALSIM_SetDigitalPWMPin(int32_t index, int32_t pin);

#ifdef __cplusplus
}
#endif

