#include "substring.h"

namespace algo {

// 560
// input: nums = [1,1,1], k = 2
// output: 2
int subarraySum(std::vector<int>& nums, int k) {
  const int size = nums.size();
  std::vector<int> pre_sum(size + 1, 0);
  for (int i = 1; i <= size; ++i) {
    pre_sum[i] = pre_sum[i - 1] + nums[i - 1];
  }

  int num = 0;
  std::unordered_map<int, int> mp_num;
  mp_num[0] = 1;
  for (int i = 1; i <= size; ++i) {
    // sum of index m to n is k,
    // m represents many pre_sum that equal to pre_sum[i],
    // the same as n
    num += mp_num[pre_sum[i] - k];
    mp_num[pre_sum[i]]++;
  }
  return num;
}

}  // namespace algo