/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid1 = (l + r) / 2;
            int mid2 = mid1 + 1;
            if (nums[mid1] < nums[mid2]) l = mid2;
            else r = mid1;
        }
        return l;
    }
};
// @lc code=end

