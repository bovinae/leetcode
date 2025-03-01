/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }

    void dfs(vector<int>& nums, int i) {
        if(i == nums.size() - 1) {
            ret.emplace_back(nums);
            return;
        }

        // eg: [1 2 3 4]
        // can be understood as: number in nums [0, i) is fixed, we swap i with [i, nums.size()-1]
        for(int j = i; j < nums.size(); j++) {
            if(i != j) swap(nums[i], nums[j]);
            dfs(nums, i+1);
            if(i != j) swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> ret;
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{1, 2, 3, 4, 5, 6};
    vector<vector<int>> ret = s.permute(nums);
    for (auto &&i : ret) {
        for (auto &&j : i) cout << j << " ";
        cout << endl;
    }
}