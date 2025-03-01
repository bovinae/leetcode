/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row, col;
        
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for (auto it = row.cbegin(); it != row.cend(); it++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[*it][j] = 0;
            }
        }

        for (auto it = col.cbegin(); it != col.cend(); it++) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][*it] = 0;
            }
        }
    }
};
// @lc code=end

