/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x < 10) return true;
        if (x % 10 == 0) return false;
        
        // 121
        int r = 0;
        while (x > r) {
            r = 10 * r + x % 10;
            x /= 10;
        }
        if (x == r || x == r / 10) return true;
        return false;
    }
};
// @lc code=end

