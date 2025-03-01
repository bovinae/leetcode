/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    // [7,1,5,3,6,4]
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;

        int max_profit = 0, pre_min = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < pre_min) {
                pre_min = prices[i];
            } else {
                max_profit = max(max_profit, prices[i] - pre_min);
            }
        }

        return max_profit;
    }
};
// @lc code=end

