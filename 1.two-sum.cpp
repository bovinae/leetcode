/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                return {m[target - nums[i]], i};
            }
            m[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;
    Solution s;
    auto ans = s.twoSum(nums, target);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
