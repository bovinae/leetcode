/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> tmp;
        vector<vector<int>> ret;
        dfs(candidates, target, 0, ret, tmp);
        return ret;
    }

private:
    void dfs(vector<int>& candidates, int target, int i, vector<vector<int>>& ret, vector<int>& tmp) {
        if (target == 0) {
            ret.push_back(tmp);
            return ;
        }
        if (i >= candidates.size()) return ;

        if (candidates[i] <= target) {
            tmp.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i+1, ret, tmp);                
            tmp.pop_back();
        }
        
        int j = i + 1;
        while (j < candidates.size()) {
            if (candidates[j] != candidates[i]) break;
            j++;
        }
        if (j < candidates.size()) { 
            // 尝试下一个数字，递归走上面的逻辑。
            dfs(candidates, target, j, ret, tmp);
        }
    }
};
// @lc code=end

int main() {
    vector<int> nums{2,5,2,1,2};
    Solution s;
    vector<vector<int>> ret = s.combinationSum2(nums, 5);
    for (auto &&i : ret) {
        for (auto &&j : i) cout << j << " ";
        cout << endl;
    }
    cout << endl;
}
