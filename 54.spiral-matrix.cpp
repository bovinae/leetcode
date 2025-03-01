/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;

        /*
        1	2	3	4
        5	6	7	8
        9	10	11	12
         */
        int row = matrix.size(), col = matrix[0].size();
        int a = 0, b = col - 1, c = 0, d = row - 1;
        
        while (a <= b && c <= d) {
            for (int i = a; i <= b; i++) {
                ret.push_back(matrix[c][i]);
            }
            for (int i = c+1; i <= d; i++) {
                ret.push_back(matrix[i][b]);
            }
            // add c != d, because if c == d, walking from left to right has added the elements
            for (int i = b-1; i >= a && c != d; i--) {
                ret.push_back(matrix[d][i]);
            }
            // add a != b, because if a == b, walking from up to down has added the elements
            for (int i = d-1; i > c && a != b; i--) {
                ret.push_back(matrix[i][a]);
            }
            a++;
            b--;
            c++;
            d--;
        }

        return ret;
    }
};
// @lc code=end

