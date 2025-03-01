/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp;
        for (int i = 0; i < m+1; i++) {
            dp.emplace_back(vector<int>(n+1, 0));
        }

        dp[0][1] = 1;
        for (int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

