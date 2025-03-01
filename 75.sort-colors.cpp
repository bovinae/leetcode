/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /* 
        steps:
        1. find the right boundary of the sorted 0;
        2. find the left boundary of the sorted 2;
        3. walk through from left to right by i:
            if nums[i] == 0, swap above right boundary; 
            else if nums[i] == 2, swap above left boundary.
     */
    void sortColors(vector<int>& nums) {
        if (nums.size() <= 1) return ;

        int l = 0, r = nums.size() - 1;
        int i = l; // i walk from left to right
        // 0,0,2,1,1,2
        while (true) { 
            // pass the sorted               
            while (l <= r && nums[l] == 0) l++;
            while (l <= r && nums[r] == 2) r--;
            if(i < l) i = l;
            if (i > r) break;

            if (nums[i] == 2) {
                swap(nums[i], nums[r]);
                r--;
                // after swap: nums[i] may be 0 or 1                
            }
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
                // after swap: nums[i] may be 1 or 2
            }
            // now nums[i] may be 1 or 2
            if (nums[i] == 1) i++;
        }
    }
};
// @lc code=end

