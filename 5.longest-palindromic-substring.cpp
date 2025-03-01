/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string tmp;
        for (int i = 0; i < s.size(); i++) {
            tmp += "#";
            tmp += s[i];
        }
        tmp += "#";

        // #a#b#a#
        int max_len = 0;
        string longest = "";
        for (int i = 0; i < tmp.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (tmp[i - j] == tmp[i +j]) {
                    continue;
                }
                int len = 2 * (j-1) + 1;
                if (len > max_len) {
                    max_len = len;
                    longest = tmp.substr(i-j+1, len);
                }
                break;
            }
        }

        string ret;
        for (int i = 0; i < longest.size(); i++) {
            if (longest[i] == '#') continue;
            ret += longest[i];
        }
        return ret;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
    return 0;
}
