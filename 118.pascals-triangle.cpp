/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret{};
        
        for (int i = 0; i < numRows; i++) {
            if (i == 0) ret.push_back({1});
            else if (i == 1) ret.push_back({1, 1});
            else {
                vector<int> tmp(i+1, 1);
                for (int j = 1; j < i; j++) {
                    tmp[j] = ret[i-1][j-1] + ret[i-1][j];
                }
                ret.push_back(tmp);
            }
        }

        return ret;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> ret = s.generate(5);
    for (auto &&i : ret) {
        for (auto &&j : i) cout << j << " ";
        cout << endl;
    }
}
