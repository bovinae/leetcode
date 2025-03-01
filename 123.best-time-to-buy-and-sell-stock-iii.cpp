/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    // find the 2 biggest ascending segment
    int maxProfit(vector<int>& prices) {
        int pre = INT_MAX;
        // record the 2 biggest ascending segment
        int b1 = 0, b2 = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] <= pre) pre = prices[i];
            else if (i+1 < prices.size() && prices[i+1] >= prices[i]) {
                continue;
            } else {
                // find the 2 biggest ascending segment
                int profit = prices[i] - pre;
                if (profit >= b1) {
                    b2 = b1;
                    b1 = profit;
                } else if (profit > b2)
                    b2 = profit;
                pre = INT_MAX;
            }
        }
        return b1 + b2;
    }
};
// @lc code=end

