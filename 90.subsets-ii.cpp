/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return {};

        sort(nums.begin(), nums.end());

        vector<vector<int>> ret;
        vector<vector<int>> pre;
        ret.push_back({});
        ret.push_back({nums[0]});
        pre.push_back({nums[0]});
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i-1] != nums[i]) {
                pre.clear();
                pre.reserve(ret.size());
                for (auto r : ret) {
                    r.push_back(nums[i]);
                    pre.push_back(r);
                }
            } else {
                for (auto &r : pre) {
                    r.push_back(nums[i]);
                }
            }
            for (auto &&v : pre) {
                ret.push_back(v);
            }
        }

        return ret;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{1, 2, 2};
    vector<vector<int>> ret = s.subsetsWithDup(nums);
    for (auto &&r : ret) {
        for (auto &&i : r) cout << i << " ";
        cout << endl;
    }
}