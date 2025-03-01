/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // [2,3,1,1,4]
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;

        int i = 0, pre_reach = 0, reach = 0;
        while (i < nums.size()) {
            // Find the max jump in each step.
            while (i <= pre_reach) {
                reach = max(reach, i + nums[i]);
                i++;
            }
            // If reach the end, return.
            if (reach >= nums.size() - 1) return true;
            // If no breakthrough, return false.
            if (reach <= pre_reach) return false;
            pre_reach = reach;
        }
        return false;
    }
};
// @lc code=end

