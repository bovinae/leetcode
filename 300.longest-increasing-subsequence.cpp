/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

#include "leetcode.h"

#include <algorithm>

// @lc code=start
class Solution {
public:
    // Greedy with Binary Search
    int lengthOfLIS(vector<int>& nums) {
        vector<int> v;
        for (int i = 0; i < nums.size(); i++) {
            if (v.empty() || v.back() < nums[i]) {
                v.push_back(nums[i]);
                continue;
            }           
            if (v.back() == nums[i]) {
                continue;
            }

            // v.back() > nums[i]
            // 1 2 5 6
            // current value = 3, replace 5 with 3
            int l = 0, r = v.size();
            while (l < r) {
                int mid = (l + r) / 2;
                if (v[mid] > nums[i]) 
                    r = mid;
                else if (v[mid] < nums[i]) 
                    l = mid + 1;
                else {
                    l = mid;
                    break;
                }
            }
            v[l] = nums[i];
        }
        return v.size();
    }
};
// @lc code=end

