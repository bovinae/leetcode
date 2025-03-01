/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int counter = 0;
        int pre_jump = 0;
        int max_jump = 0;
        int i = 0;
        while (i < nums.size()) {
            while (i <= pre_jump) {
                max_jump = max(max_jump, nums[i] + i);
                i++;
            }
            if (max_jump <= pre_jump && pre_jump < nums.size()-1) return -1;
            counter++;
            if (max_jump >= nums.size()-1) return counter;
            pre_jump = max_jump;
        }
        return counter;
    }
};
// @lc code=end

