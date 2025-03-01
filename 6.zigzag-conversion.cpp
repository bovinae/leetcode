/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
    P   A   H   N
    A P L S I I G
    Y   I   R
    0 4 8 12
    1 3 5 7 9
    2 6 10

    P     I    N
    A   L S  I G
    Y A   H R
    P     I
    0 6 12 i+2*(numRows-1)*j
    1 5 7 11 13 17 i+2*(numRows-1)*j and -i+2*(numRows-1)*(j+1)
    2 4 8 10 14 16 
    3 9 15 i+2*(numRows-1)*j
    */
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int n = s.size();
        string ret;
        // 算公差
        int d = 2*(numRows-1);
        // 遍历每行
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; i+j < n; j += d) {
                ret += s[i+j];
                if (i != 0 && i != numRows-1 && j+d-i < n)
                    ret += s[j+d-i];
            }
        }
        return ret;
    }
};
// @lc code=end

