#include <gtest/gtest.h>
#include <time.h>

#include <cstdlib>
#include <iostream>

#include "singleton.h"

TEST(test_design_pattern, singleton_test_case) {
  design_pattern::LSingletonWithLock::GetInstance()->Print();
  design_pattern::LSingletonWithStatic::GetInstance().Print();
  design_pattern::HSingletonWithStatic::GetInstance()->Print();
  design_pattern::HSingletonWithCallOnce::GetInstance()->Print();
}