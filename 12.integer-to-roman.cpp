/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        string M[] = {"", "M", "MM", "MMM"};

        return M[num/1000] + C[num%1000/100] + X[num%100/10] + I[num%10];
    }
};
// @lc code=end

