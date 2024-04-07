#include "ordinary_array.h"

namespace algo {

// 53
// input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// output: 6
// explain: sum of [4,-1,2,1] is 6
int maxSubArray(std::vector<int>& nums) {
    if (nums.empty()) {
        return -1;
    }
    int max_sum = nums[0];
    int tmp_sum = nums[0];
    for (int i = 1; i < (int)nums.size(); ++i) {
        tmp_sum += nums[i];
        tmp_sum = std::max(tmp_sum, nums[i]);
        max_sum = std::max(max_sum, tmp_sum);
    }
    return max_sum;
}

// 56
// input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// output: [[1,6],[8,10],[15,18]]
// explain: [1,3] and [2,6] are overlap
std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) {
        return {};
    }
    sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> output{intervals[0]};
    for (int i = 1; i < (int)intervals.size(); ++i) {
        if (intervals[i][0] > output.back()[1]) {
            output.push_back(intervals[i]);
        } else {
            output.back()[1] = std::max(output.back()[1], intervals[i][1]);
        }
    }
    return output;
}

// 189
// input: nums = [1,2,3,4,5,6,7], k = 3
// output: [5,6,7,1,2,3,4]
void reverse(std::vector<int>& nums, int start, int end) {
    while (start < end) {
        std::swap(nums[start], nums[end]);
        ++start;
        --end;
    }
}

void rotate(std::vector<int>& nums, int k) {
    if (nums.empty() || k <= 0) {
        return;
    }
    k %= nums.size();
    reverse(nums, 0, nums.size() - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.size() - 1);
}

// 238
// input: nums = [1,2,3,4]
// output: [24,12,8,6]
std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> output(n,1);
    for(int i=1; i<n; i++){
        output[i] = output[i-1] * nums[i-1];
    }
    int right = 1;
    for(int i=n-1; i>=0; i--){
        output[i] *= right;
        right *= nums[i];
    }
    return output;
}

} // namespace algo
