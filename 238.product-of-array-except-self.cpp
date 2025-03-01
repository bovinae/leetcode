/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

#include "iostream"
#include "vector"

using namespace std;

// @lc code=start
class Solution {
public:
    // [-1,1,0,-3,3]
    vector<int> productExceptSelf(vector<int>& nums) { 
        vector<int> ret(nums.size(), 1);
        // 从左到右累积乘
        for (int i = 0; i < nums.size()-1; i++) {
            ret[i+1] = ret[i] * nums[i];
        }
        // 从右到左累积乘
        // now vector ret has values, we need tmp variable right
        int right = 1;
        for (int i = nums.size() - 1; i > 0; i--) {
            right *= nums[i];
            ret[i-1] = right;
        }
    }

    // use prefix product and suffix product
    vector<int> productExceptSelf1(vector<int>& nums) {
        vector<int> prefix(nums.size(), 1);
        vector<int> suffix(nums.size(), 1);
        for (int i = 0; i < nums.size()-1; i++) {
            prefix[i+1] = prefix[i] * nums[i];
        }
        for (int i = nums.size()-1; i >= 1; i--) {
            suffix[nums.size()-i] = suffix[nums.size()-i-1] * nums[i];
        }

        vector<int> ret(nums.size(), 0);        
        for (int i = 0; i < nums.size(); i++) {
            ret[i] = prefix[i] * suffix[nums.size()-i-1];
        }
        return ret;
    }
};
// @lc code=end
