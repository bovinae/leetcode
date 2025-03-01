/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
        4,1,-1,3
        */
       int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 0 && nums[i] < n && nums[i] != i && nums[i] != nums[nums[i]]) {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] != i && i != 0) return i;
        }
        // the digit in position 0 maybe not swapped
        return (nums[0] == n) ? n + 1 : n;
    }
};
// @lc code=end

int main() {
    vector<int> nums{1,1};
    Solution s;
    cout << s.firstMissingPositive(nums) << endl;
}
