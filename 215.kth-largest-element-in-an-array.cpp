/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
    partition like quick sort:
    1 2 3 4
    4 3 2 1
    1 4 6 5
    */
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;        
        while (l < r) {
            // use last element to partition
            int s = l;
            int t = r;
            while (l < r) {
                // 不能取等号，防止较大的元素也放到左边了。
                while (l < r && nums[l] < nums[t]) l++;
                while (l < r && nums[r] >= nums[t]) r--;
                swap(nums[l], nums[r]);
                // 不能移动，防止结束时指向一个较小元素，然后后面swap导致这个较小元素被交换到了右边。
                // l++; r--;
            }
            // l == r
            swap(nums[l], nums[t]);

            if (t - l + 1 == k) return nums[l];
            if (t - l + 1 > k) {
                l++;
                r = t;
            } else {
                k -= t - l + 1;
                l = s;
                r--;
            }
        }
        // l == r
        return nums[l];
    }
};
// @lc code=end

