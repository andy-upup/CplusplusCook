#include "sliding_window.h"

namespace algo {

// 3
// input: s = "abcabcbb"
// output: 3
// explain: "abc"
int lengthOfLongestSubstring(std::string s) {
    int max_len = 0;
    std::vector<int> mask(128, -1);
    int start = -1;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (mask[s[i]] > start) {
            start = mask[s[i]];
        }
        mask[s[i]] = i;
        max_len = std::max(max_len, i - start);
    }
    return max_len;
}

// 438
// input: s = "cbaebabacd", p = "abc"
// output: [0,6]
// explain: return start index
bool check(std::vector<int>& vec1, std::vector<int>& vec2) {
    if (vec1.size() != 26 || vec2.size() != 26) {
        return false;
    }
    for (int i = 0; i < 26; ++i) {
        if (vec1[i] != vec2[i]) {
            return false;
        }
    }
    return true;
}

std::vector<int> findAnagrams(std::string s, std::string p) {
    std::vector<int> output;
    const int size1 = s.size();
    const int size2 = p.size();
    std::vector<int> table1(26, 0);
    std::vector<int> table2(26, 0);
    for (int i = 0; i < size1; ++i) {
        table2[p[i] - 'a']++;
    }
    for (int l = 0, r = 0; r < size1; ++r) {
        table1[s[r] - 'a']++;
        if (r - l + 1 > size2) {
            table1[s[l++] - 'a']--;
        }
        if (check(table1, table2)) {
            output.push_back(l);
        }
    }
    return output;
}

} // namespace algo