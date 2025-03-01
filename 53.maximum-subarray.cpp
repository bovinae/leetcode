/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    // [-2, 1,-3,4,-1,2,1,-5,4]
    // From left to right, if previous sum <= 0, then it should not contribute, set the sum to current number.
    // Find the max sum while walking through the array.
    int maxSubArray(vector<int>& nums) {
        int total = 0, ret = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            if (total < 0) {
                total = 0;
            }
            total += nums[i];
            ret = max(ret, total);
        }

        return ret;
    }
};
// @lc code=end

