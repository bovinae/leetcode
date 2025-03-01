/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> points;
        for (auto &&building : buildings) {
            // building left upper point
            points.push_back(make_pair(building[0], -building[2]));
            // building right upper point
            points.push_back(make_pair(building[1], building[2]));
        }

        // sort by pair.first(x axis)
        sort(points.begin(), points.end());

        multiset<int> pq{0};
        // record the skyline height
        int ongoingHeight = 0;
        vector<vector<int>> ans;
        for(auto &&point : points) {
            if (point.second < 0) pq.insert(-point.second);
            else pq.erase(pq.find(point.second));

            int top = *pq.rbegin();
            if (ongoingHeight != top) {
                ongoingHeight = top;
                ans.push_back({point.first, ongoingHeight});
            }
        }

        return ans;
    }
};
// @lc code=end

