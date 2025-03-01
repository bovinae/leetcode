/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) return x;

        /*
        1 2 3 4
        */
        int l = 1, r = x / 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            long long tmp = m;
            tmp *= m;
            if (tmp == x) return m;
            else if (tmp < x) l = m + 1;
            else r = m - 1;
        }
        return r;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.mySqrt(4) << endl;
}
