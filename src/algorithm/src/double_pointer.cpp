#include "double_pointer.h"

namespace algo {

// 283
// input: nums = [0,1,0,3,12]
// output: [1,3,12,0,0]
void moveZeroes(std::vector<int>& nums) {
    int i = 0;
    for (int j = 0; j < (int)nums.size(); ++j) {
        if (nums[j] != 0) {
            nums[i++] = nums[j];
        }
    }
    while (i < (int)nums.size()) {
        nums[i++] = 0;
    }
}

// 11
// input: [1,8,6,2,5,4,8,3,7]
// output: 49
int maxArea(std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;
    while (left < right) {
        int h = std::min(height[left], height[right]);
        max_area = std::max(max_area, h * (right - left));
        if (height[left] < height[right]) {
            ++left;
        } else {
            --right;
        }
    }
    return max_area;
}

// 15
// input:
// output:
std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    const int size = nums.size();
    if (size < 3) {
        return {};
    }

    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> output;
    for (int i = 0; i < size; ++i) {
        if (nums[i] > 0) {
            return output;
        }
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = size - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                output.push_back({nums[i], nums[left], nums[right]});
                while (left + 1 < right && nums[left] == nums[left + 1]) {
                    ++left;
                }
                while (right - 1 > left && nums[right - 1] == nums[right]) {
                    --right;
                }
                ++left;
                --right;
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }
    return output;
}

}