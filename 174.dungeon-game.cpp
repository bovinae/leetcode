/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    // dp
    /*
    1   -3  3
    0   -2  0
    -3  -3  -3
    */
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size(), col = dungeon[0].size();
        vector<vector<int>> dp(row+1, vector<int>(col+1, INT_MAX));
        dp[row][col-1] = 1;
        dp[row-1][col] = 1;

        for (int i = row-1; i >= 0; i--) {
            for (int j = col-1; j >= 0; j--) {
                int need = min(dp[i+1][j], dp[i][j+1]) - dungeon[i][j];
                dp[i][j] = (need <= 0) ? 1 : need;
            }
        }

        return dp[0][0];
    }
};
// @lc code=end

