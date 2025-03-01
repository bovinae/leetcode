/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
    1,2,3,4,5,6,7,8,9,10
    8,9,10,1,2,3,4,5,6,7

    reverse [0,n)
    reverse [0,k)
    reverse [k,n)
    */
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        reverse(nums, 0, n);
        reverse(nums, 0, k);
        reverse(nums, k, n);
    }

private:
    void reverse(vector<int>& nums, int i, int j) {
        j--;
        while (i < j) {
            swap(nums[i++], nums[j--]);
        }
    }
};
// @lc code=end

