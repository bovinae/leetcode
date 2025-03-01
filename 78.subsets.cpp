/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
      
      1
      2 12
      3 13 23 123
    */
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans{};
        ans.push_back({});

        for (int i = 0; i < nums.size(); i++) {
            int len = ans.size();
            for (int j = 0; j < len; j++) {
                vector<int> tmp = ans[j];
                tmp.push_back(nums[i]);
                ans.push_back(tmp);
            }
        }

        return ans;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{1,2,3};
    s.subsets(nums);
    return 0;
}
