/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
    [3,0,2]
    [9,6,4,2,3,5,7,0,1]
    */
    // a^b^b == a
    int missingNumber(vector<int>& nums) {
        int tmp = 0, i = 0;
        for (i = 0; i < nums.size(); i++) {
            tmp ^= i ^ nums[i];
        }
        tmp ^= i;
        return tmp;
    }

    int missingNumber1(vector<int>& nums) {
        vector<int> tmp(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i++) {
            tmp[nums[i]] = 1;
        }
        for (int i = 0; i < nums.size() + 1; i++) {
            if (tmp[i] == 0) return i;
        }
        return -1;
    }
};
// @lc code=end

