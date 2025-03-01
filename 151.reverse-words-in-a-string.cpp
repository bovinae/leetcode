/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    // s = "  hello world  "
    string reverseWords(string s) {
        string ret;
        int i, start = -1;
        for (i = s.size() - 1; i >= 0; i--) {
            if (start == -1) {
                if (s[i] == ' ') continue;
                start = i;
            }
            if (s[i] == ' ') {
                ret.append(s.substr(i+1, start-i) + ' ');
                start = -1;
            }
        }
        if (start != -1) ret.append(s.substr(i+1, start-i) + ' ');
        ret.erase(ret.size()-1, 1);
        return ret;
    }
};
// @lc code=end

