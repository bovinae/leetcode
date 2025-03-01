/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        // process prefix
        int sign = 0;
        int firstNumPos = findFirstNumPos(s, sign);
        if (firstNumPos == -1) return 0;         

        int sum = 0;
        for (int i = firstNumPos; i < s.size(); i++) {
            if (s[i] < '0' || s[i] > '9') break;
            if (sum > 214748364) {
                return (sign == -1) ? -2147483648 : 2147483647;
            } else if (sum == 214748364) {
                if (sign == -1 && s[i] - '0' >= 8) return 2147483648;
                else if ((sign == 1 && s[i] - '0' > 7)) return 2147483647;
            }
            sum = 10 * sum + (s[i] - '0');
        }

        return sign * sum;
    }

    int findFirstNumPos(string &s, int &sign) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                sign = (sign == 0) ? 1 : sign;
                return i;
            }
            if (s[i] == '+' || s[i] == '-') {
                if (sign != 0) return -1;
                sign = (s[i] == '+') ? 1 : -1;
                continue;
            }
            if (sign != 0 || s[i] != ' ') return -1;
        }
        return -1;
    }
};
// @lc code=end

