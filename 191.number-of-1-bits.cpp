/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /* 
    00000000000000000000000000001011
    00000000000000000000000000001010
    00000000000000000000000000001001
    */
    int hammingWeight(uint32_t n) {
        int ret = 0;
        while (n != 0) {
            n &= n - 1;
            ret++;
        }
        return ret;
    }
};
// @lc code=end

