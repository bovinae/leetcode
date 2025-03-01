/*
 * @lc app=leetcode id=258 lang=cpp
 *
 * [258] Add Digits
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
        while (num / 10 > 0) {
            int tmp = 0;
            while (num / 10 > 0) {
                tmp += num % 10;
                num /= 10;
            }
            tmp += num;
            num = tmp;
        }
        return num;
    }
};
// @lc code=end

