/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    // tow-pointer
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !is_alphanumeric(s[l])) l++;
            while (l < r && !is_alphanumeric(s[r])) r--;

            if (s[l] == s[r]) {
                l++; r--;
                continue;
            }
            if (is_numeric(s[l])) return false;
            char c1 = s[l];
            char c2 = s[r];
            if (is_upperalpha(c1)) c1 += 'a' - 'A';
            if (is_upperalpha(c2)) c2 += 'a' - 'A';
            if (c1 != c2) return false;
            l++; r--;
        }
        return true;
    }

private:
    bool is_alphanumeric(char c) {
        return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9');
    }
    bool is_numeric(char c) {
        return '0' <= c && c <= '9';
    }
    bool is_upperalpha(char c) {
        return 'A' <= c && c <= 'Z';
    }
};
// @lc code=end

