/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 0, j = 31;
        while (i < j) {
            bool iSet = (n & (1 << i)) != 0; // true represent setted
            bool jSet = (n & (1 << j)) != 0;
            // i，j bit不同
            if (iSet ^ jSet) {
                // 相当于把i，j bit取反
                n ^= 1 << i;
                n ^= 1 << j;
            }
            // i，j bit相同不用处理

            i++;
            j--;
        }
        return n;
    }
};
// @lc code=end

