/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        while (i >= 0) {
            if (s[i] != ' ') break;
            i--;
        }
        int j = i;
        while (i >= 0) {
            if (s[i] == ' ') break;
            i--;
        }
        return j - i;
    }
};
// @lc code=end

