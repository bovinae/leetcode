/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
    hors
    r
    1 2 3 3
    ro
    2 1 2
    hor s
    ro s
    dp[i][j] = ?
    if (word1[i] == word2[j]) dp[i][j] = dp[i-1][j-1]
    else dp[i][j] = 1 + min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j])
    */
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();

        vector<vector<int>> dp;
        for (int i = 0; i < m+1; i++) {
            dp.push_back(vector<int>(n+1, i));
        }
        for (int i = 0; i < n+1; i++) {
            dp[0][i] = i;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (word1[i] == word2[j]) dp[i+1][j+1] = dp[i][j];
                else {
                    int tmp = min(dp[i][j], dp[i+1][j]);
                    tmp = min(tmp, dp[i][j+1]);
                    dp[i+1][j+1] = 1 + tmp;
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end

