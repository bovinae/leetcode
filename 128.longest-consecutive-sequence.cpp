/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            // nums[i]-1存在，表示nums[i]不是该sequence的最小值
            if (m.count(nums[i]-1) != 0) continue;

            // nums[i]-1不存在，表示nums[i]是该sequence的最小值
            int cur = nums[i];
            int len = 1;
            while (m.count(++cur) != 0) len++;
            ret = max(ret, len);
        }

        return ret;
    }
};
// @lc code=end

