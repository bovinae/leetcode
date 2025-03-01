/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> code{};
        for (int i = 0; i < pow(2, n); i++) {
            int gray = 0;
            int mask = 1;
            for (int j = 0; j < n-1; j++) {
                // i的第j bit
                int tmp1 = i & mask;
                // i的第j+1 bit
                mask <<= 1;
                int tmp2 = (i & mask) >> 1;
                // 放到gray的第j bit
                gray |= tmp1 ^ tmp2;
            }
            // 处理最高bit
            gray |= i & mask;
            code.emplace_back(gray);
        }
        return code;
    }
};
// @lc code=end

