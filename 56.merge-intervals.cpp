/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {return a[0] < b[0];});

        vector<vector<int>> ret;
        ret.emplace_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (ret.back()[1] >= intervals[i][0]) {
                ret.back()[1] = max(ret.back()[1], intervals[i][1]);
            } else {
                ret.emplace_back(intervals[i]);
            }
        }

        return ret;
    }
};
// @lc code=end
