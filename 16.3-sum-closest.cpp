/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;

        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];
        for (int first = 0; first < nums.size() - 2; first++) {
            int second = first + 1;
            int third = nums.size() - 1;
            while (second < third) {
                int curSum = nums[first] + nums[second] + nums[third];

                if (curSum == target) return target;
                // update closest
                if (abs(curSum - target) < abs(closest - target))
                    closest = curSum;
                if (curSum < target) second++;
                else third--;
            }
        }
        return closest;
    }
};
// @lc code=end

int main() {
    vector<int> nums{-1,2,1,-4};
    Solution s;
    cout << s.threeSumClosest(nums, 1) << endl;
}
