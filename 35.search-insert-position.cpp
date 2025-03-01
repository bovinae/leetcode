/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int searchInsert1(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (target < nums[m]) r = m;
            else if (target > nums[m]) l = m + 1;
            else r = m;
        }
        if (nums[l] < target) return nums.size();
        return l;
    }

    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;

        int l = 0, r = nums.size();
        while (l < r) {
            int m = (l + r) / 2;
            if (target > nums[m]) l = m + 1;
            else r = m;
        }
        return l;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{1,3,5,6};
    cout << s.searchInsert(nums, 1) << endl;
}
