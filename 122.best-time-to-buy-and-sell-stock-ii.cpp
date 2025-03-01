/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    // collect each ascending segment
    int maxProfit(vector<int>& prices) {
        int pre = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] <= pre) pre = prices[i];
            else if (i+1 < prices.size() && prices[i+1] >= prices[i]) {
                continue;
            } else {
                profit += prices[i] - pre;
                pre = INT_MAX;
            }
        }
        return profit;
    }
};
// @lc code=end

