/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
    3 2 2 1
    2 times dp:
    dp [0, nums.size()-2] and [1, nums.size()-1]
    dp[n]=max(dp[n-1], dp[n-2]+nums[n]);
    */
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        if (nums.size() == 3) {
            int tmp = max(nums[0], nums[1]);
            return max(tmp, nums[2]);
        }

        return max(do_rob(nums, 0, nums.size()-2), do_rob(nums, 1, nums.size()-1));
    }

private:
    int do_rob(vector<int>& nums, int i, int j) {
        vector<int> dp(j-i+1, 0);       

        dp[0] = nums[i];
        dp[1] = max(nums[i], nums[i+1]);

        for (int k = i+2; k <= j; k++) {
            dp[k-i] = max(dp[k-i-1], dp[k-i-2] + nums[k]);
        }

        return dp[j-i];
    }    
};
// @lc code=end

