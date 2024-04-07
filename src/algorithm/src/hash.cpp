#include "hash.h"

namespace algo {
// 1
// input: nums = [2,7,11,15], target = 9
// output: [0,1]
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::map<int, int> mp_nums;
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (mp_nums.count(target - nums[i])) {
            return {i, mp_nums[target - nums[i]]};
        } else {
            mp_nums[nums[i]] = i;
        }
    }
    return {};
}

// 49
// input: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
// output: [["bat"],["nat","tan"],["ate","eat","tea"]]
std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> mp;
    for (auto& str: strs) {
        std::string key = str;
        std::sort(key.begin(), key.end());
        mp[key].emplace_back(str);
    }

    std::vector<std::vector<std::string>> output;
    for (auto& [key, val]: mp) {
        output.emplace_back(val);
    }
    return output;
}

// 128
// input: nums = [100,4,200,1,3,2]
// output: 4
// explain: [1, 2, 3, 4]
int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> num_set(nums.begin(), nums.end());
    int max_len = 0;
    int seq_len = 0;
    for (auto num: num_set) {
        if (!num_set.count(num - 1)) {
            seq_len = 1;
            while (num_set.count(++num)) {
                ++seq_len;
            }
            max_len = std::max(max_len, seq_len);
        }
    }
    return max_len;
}

} // namespace algo