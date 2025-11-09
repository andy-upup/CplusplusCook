#include "bit_operation.h"

namespace algo {
int oddTimesNum(const std::vector<int>& nums) {
  int num = 0;
  for (int i = 0; i < nums.size(); ++i) {
    num ^= nums[i];
  }
  return num;
}

std::vector<int> oddTimesNum2(const std::vector<int>& nums) {
  int xor_num2 = 0;
  for (int i = 0; i < nums.size(); ++i) {
    xor_num2 ^= nums[i];
  }
  //   int flag = 1;
  //   while ((xor_num2 & flag) != 1) {
  //     flag <<= 1;
  //   }
  int flag = (~xor_num2 + 1) & xor_num2;
  int num1 = 0;
  for (int i = 0; i < nums.size(); ++i) {
    if ((nums[i] & flag) == 1) {
      num1 ^= nums[i];
    }
  }
  int num2 = num1 ^ xor_num2;
  return {num1, num2};
}
}  // namespace algo