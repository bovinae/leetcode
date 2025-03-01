/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;

        int pre = 1;
        int cur = 1;
        for (int i = 2; i <= n; i++) {
            int tmp = pre + cur;
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};
// @lc code=end

