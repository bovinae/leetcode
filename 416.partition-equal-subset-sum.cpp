/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
    1,5,11,5 : 11
    dp[0]
    dp[1]
    dp[6]
    dp[5]
    dp[11]
    dp[10]
    */
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<bool> dp(target+1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= nums[i]; j--) {
                if (dp[j-nums[i]]) dp[j] = true;
            }
        }

        return dp[target];
    }
};
// @lc code=end

