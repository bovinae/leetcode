/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int k) {
        if (k == word.size()) return true;
        if (board[i][j] != word[k]) return false;
        k++;
        if (k == word.size()) return true;
        
        char tmp = board[i][j];
        board[i][j] = ' ';
        int ret = 0;
        if (j + 1 < col && board[i][j+1] != ' ') {
            ret |= dfs(board, word, i, j + 1, k);
            if (ret) return true;
        }
        if (i + 1 < row && board[i+1][j] != ' ') {
            ret |= dfs(board, word, i + 1, j, k);
            if (ret) return true;
        }
        if (j - 1 >= 0 && board[i][j-1] != ' ') {
            ret |= dfs(board, word, i, j - 1, k);
            if (ret) return true;
        }
        if (i - 1 >= 0 && board[i-1][j] != ' ') {
            ret |= dfs(board, word, i - 1, j, k);
            if (ret) return true;
        }

        board[i][j] = tmp;
        return false;
    }

    int row, col;
};
// @lc code=end

