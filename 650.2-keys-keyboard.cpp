/*
 * @lc app=leetcode id=650 lang=cpp
 *
 * [650] 2 Keys Keyboard
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
    A
    AA
    AAA AAAA
    AAAAAA AAAAAAAA
    dp[1]=0
    dp[2]=2
    dp[3]=3
    dp[4]=dp[2]+2=4
    dp[5]=5
    dp[6]=dp[3]+2
    dp[7]=7
    dp[8]=dp[4]+2=6
    dp[9]=dp[9/3]+3
    dp[15]=dp[15/3]+3
    n%2==0: dp[n] = dp[n/2] + 2
    n%3==0: dp[n] = dp[n/3] + 3
    */
    int minSteps(int n) {
        if(n <= 1) return 0;

        vector<int> dp(n+1, 0);
        dp[2] = 2;
        if (n >= 3) dp[3] = 3;
        for (int i = 2; i <= n; i++) {
            int j;
            int k = int(sqrt(i));
            for (j = 2; j <= k; j++) {
                if (i % j == 0) {
                    dp[i] = dp[i / j] + j;
                    break;
                }
            }
            if (j == k + 1)
                dp[i] = i;
        }

        return dp[n];
    }
};
// @lc code=end

