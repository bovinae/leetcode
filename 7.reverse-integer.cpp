/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        // -123
        int ret = 0;
        int upper = (pow(2, 31) - 1) / 10;
        int lower = -pow(2, 31) / 10;
        while (x != 0) {
            if (ret > upper || ret < lower) return 0;
            ret = 10 * ret + x % 10;
            x /= 10;
        }
        return ret;
    }
};
// @lc code=end

int main() {
    cout << -123 % 10 << endl;
}
