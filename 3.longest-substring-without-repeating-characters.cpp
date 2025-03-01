/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = -1;
        int max_len = 0;
        unordered_map<char, int> pos;
        for (int i = 0; i < s.size(); i++) {
            if (pos.count(s[i]) && left < pos[s[i]]) {
                left = pos[s[i]];
            }
            max_len = max(max_len, i - left);
            pos[s[i]] = i;           
        }
        return max_len;
    }
};
// @lc code=end

