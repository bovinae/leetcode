/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> tmp;
        bt(n, k, 1, ret, tmp);
        return ret;
    }

private:
    void bt(int n, int k, int i, vector<vector<int>>& ret, vector<int>& tmp) {
        if (k == tmp.size()) {
            ret.emplace_back(tmp);
            return ;
        }
        if (i > n) return ;
   
        tmp.push_back(i);
        bt(n, k, i+1, ret, tmp);
        tmp.pop_back();

        if (i+1 <= n) {
            bt(n, k, i+1, ret, tmp);
        }
    }
};
// @lc code=end

