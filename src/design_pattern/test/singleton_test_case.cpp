#include <gtest/gtest.h>
#include <time.h>

#include <cstdlib>
#include <iostream>

#include "singleton.h"

TEST(test_design_pattern, singleton_test_case) {
    LSingletonWithLock::GetInstance()->Print();
    LSingletonWithStatic::GetInstance().Print();
    HSingletonWithStatic::GetInstance()->Print();
    HSingletonWithCallOnce::GetInstance()->Print();
}