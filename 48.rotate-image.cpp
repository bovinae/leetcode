/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
     1. flip along the horizontal centerline;
     2. flip along the back-diagonal.

     6  1   9   11      15 14  12  16       15  13  2   6
     2  4   8   10  =>  13 3   6   7    =>  14  3   4   1
     13 3   6   7       2  4   8   10       12  6   8   9
     15 14  12  16      6  1   9   11       16  7   10  11
     */
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size() / 2; i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                swap(matrix[i][j], matrix[matrix.size()-i-1][j]);
            }
        }

        for (int i = 0; i < matrix.size() - 1; i++) {
            for (int j = i+1; j < matrix[0].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
// @lc code=end

