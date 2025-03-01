/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) return triangle[0][0];

        int min_val;
        for (int i = 1; i < triangle.size(); i++) {
            min_val = INT_MAX;
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) triangle[i][j] += triangle[i-1][j];
                else if (j == triangle[i].size()-1) triangle[i][j] += triangle[i-1][j-1];
                else {
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
                }
                min_val = min(min_val, triangle[i][j]);
            }
        }

        return min_val;
    }
};
// @lc code=end

