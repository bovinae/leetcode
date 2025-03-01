/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dp;
        for (int i = 0; i < m+1; i++) {
            dp.emplace_back(vector<int>(n+1, INT_MAX));
        }

        dp[0][1] = 0;
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dp[i+1][j+1] = min(dp[i+1][j], dp[i][j+1]) + grid[i][j];
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

int main() {
    vector<vector<int>> grid{{1,3,1},{1,5,1},{4,2,1}};
    Solution s;
    cout << s.minPathSum(grid) << endl;
}