/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string ret = strs[0];
        for (int i = 1; i < strs.size(); i++) {
            if (ret.empty()) return "";
            int j;
            for (j = 0; j < ret.size() && j < strs[i].size(); j++) {
                if (strs[i][j] != ret[j]) break;
            }
            ret = ret.substr(0, j);
        }
        return ret;
    }
};
// @lc code=end

