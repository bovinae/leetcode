/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    // 226
    // recursion
    int numDecodings1(string s) {
        if (s.size() == 0) return 1;
        if (s.size() == 1) {
            if (s[0] >= '1' && s[0] <= '9')
                return 1;
            else
                return 0;
        }
        
        int ret = 0;
        if (s[0] >= '1' && s[0] <= '9')
            ret += numDecodings1(s.substr(1, s.size() - 1));
        if ((s[0] == '1' && (s[1] >= '0' && s[1] <= '9')) || (s[0] == '2' && (s[1] >= '0' && s[1] <= '6')))
            ret += numDecodings1(s.substr(2, s.size() - 2));
        return ret;
    }

    // 111111111111111111111111111111111111111111111
    /* dp: dp[n] = 
     case 1: dp[n-1] + dp[n-2], where s[n] and s[n-1,n] are valid;
     case 2: dp[n-1], where s[n] is valid;
     case 3: dp[n-2], where s[n-1,n] is valid;
     case 4: return 0, where both s[n] and s[n-1,n] are invalid.
     */
    int numDecodings(string s) {
        int pre = 1, cur = 0;
        if (s.size() > 0 && s[0] >= '1' && s[0] <= '9')
            cur = 1;
        for (int i = 1; i < s.size(); i++) {
            int tmp = 0;
            if (s[i] >= '1' && s[i] <= '9')
                tmp += cur;
            if ((s[i-1] == '1' && (s[i] >= '0' && s[i] <= '9')) || (s[i-1] == '2' && (s[i] >= '0' && s[i] <= '6')))
                tmp += pre;
            if (tmp == 0)
                return 0;
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};
// @lc code=end

