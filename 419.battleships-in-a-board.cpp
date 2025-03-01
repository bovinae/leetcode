/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        int ships = 0;

        for  (int i = 0; i < row; i++) {
            for  (int j = 0; j < col; j++) {
                if (board[i][j] != 'X') continue;

                ships++;         
                int k = j;
                while (k < col && board[i][k] == 'X') {
                    board[i][k] = '.';
                    k++;
                }
                k = i + 1;
                while (k < row && board[k][j] == 'X') {
                    board[k][j] = '.';
                    k++;
                }
            }
        }

        return ships;
    }
};
// @lc code=end

