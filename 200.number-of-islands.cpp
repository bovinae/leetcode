/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    // dfs
    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();

        int ret = 0;        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    ret++;
                    dfs(grid, i, j);
                }
            }
        }
        return ret;
    }

private:
    int row;
    int col;

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= row) return;
        if (j < 0 || j >= col) return;
        if(grid[i][j] == '0' || grid[i][j] == ' ') return;
        
        grid[i][j] = ' ';
        dfs(grid, i, j+1);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i-1, j);
    }
};
// @lc code=end

