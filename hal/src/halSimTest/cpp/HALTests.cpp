/*----------------------------------------------------------------------------*/
/* Copyright (c) FIRST 2015. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "HAL/HAL.h"

#include "gtest/gtest.h"

namespace hal {
    TEST(HALTests, RuntimeType) {
        EXPECT_EQ(HAL_RuntimeType::HAL_Mock, HAL_GetRuntimeType());
    }
}