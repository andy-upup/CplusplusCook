#include <gtest/gtest.h>
#include <time.h>

#include <cstdlib>
#include <iostream>

#include "bit_operation.h"

TEST(test_bit_operation, odd_times_num1_unit_test) {
  std::vector<int> nums{1, 1, 2, 2, 3};
  int num = algo::oddTimesNum(nums);
  std::cout << "oddTimesNum: " << num << std::endl;
}

TEST(test_bit_operation, odd_times_num2_unit_test) {
  std::vector<int> nums{1, 1, 2, 2, 3, 4};
  std::vector<int> num = algo::oddTimesNum2(nums);
  std::cout << "oddTimesNum: " << num[0] << " " << num[1] << std::endl;
}