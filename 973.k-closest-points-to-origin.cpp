/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq(points.begin(), points.end());
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }

private:
    struct cmp{
        bool operator()(vector<int>& a, vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
        }
    };
};
// @lc code=end

