/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> ret;
        dfs(candidates, target, 0, ret, tmp);
        return ret;
    }

private:
    // 2,3,6,7
    void dfs(vector<int>& candidates, int target, int i, vector<vector<int>>& ret, vector<int>& tmp) {
        if (target == 0) {
            ret.push_back(tmp);
            return ;
        }

        if (candidates[i] <= target) {
            tmp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, ret, tmp);
            tmp.pop_back();  
        }
        
        if (i < candidates.size() - 1) { 
            // 尝试下一个数字，递归走上面的逻辑。
            dfs(candidates, target, i+1, ret, tmp);
        }
    }
};
// @lc code=end

int main() {
    vector<int> nums{2,3,6,7};
    Solution s;
    vector<vector<int>> ret = s.combinationSum(nums, 7);
    for (auto &&i : ret) {
        for (auto &&j : i) cout << j << " ";
        cout << endl;
    }
    cout << endl;
}
