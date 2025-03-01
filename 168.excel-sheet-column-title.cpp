/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
    26-Z, 27-AA, 52-AZ
    */
    string convertToTitle1(int columnNumber) {
        string ret{};
        while (columnNumber != 0) {
            char c = columnNumber % 26;
            columnNumber /= 26;            
            if (c > 0) {
                ret += 'A' + c - 1;
            } else {
                // force lower char to 'Z', higher char--
                ret += 'Z';
                columnNumber--;
            }
        }
        for (int i = 0; i < ret.size()/2; i++) {
            swap(ret[i], ret[ret.size()-i-1]); 
        }        
        return ret;
    }
};
// @lc code=end

