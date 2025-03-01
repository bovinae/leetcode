/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // [1 1 2]
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();

        int cnt = 1;
        for(int i = 1; i < nums.size(); i++) {
            if((nums[i] ^ nums[i-1]) != 0) {
                nums[cnt++] = nums[i];
            }
        }
        return cnt;
    }
};
// @lc code=end
