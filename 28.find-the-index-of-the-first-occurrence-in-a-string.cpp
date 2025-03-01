/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;

        int l = 0, r = 0;
        while (l <= (haystack.size() - needle.size())) {
            int i;
            for (i = 0; i < needle.size() && r < haystack.size(); r++, i++) {
                if (haystack[r] != needle[i]) break;
            }
            if (i == needle.size()) return l;
            l++;
            r=l;
        }
        return -1;
    }
};
// @lc code=end

