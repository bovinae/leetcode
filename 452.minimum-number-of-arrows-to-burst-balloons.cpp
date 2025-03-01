/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    // [[1,6],[2,8],[7,12],[10,16]]
    // (a1,b1),(a2,b2),(a3,b3),(a4,b4),(a5,b5),(a6,b6),
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() <= 1) return points.size();

        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {return a[0] < b[0];});
        int total = 0;
        vector<int> intersection;
        for (int i = 0; i < points.size()-1; i++) {
            intersection = points[i];
            while (i < points.size()-1) {                
                intersection = get_interact(intersection, points[i+1]);
                if (intersection[0] == INT_MAX) break;
                i++;                
            }
            total++;
        }
        if (intersection[0] == INT_MAX) total++;
        
        return total;
    }

private:
    vector<int> get_interact(vector<int> &a, vector<int> &b) {
        if (a[1] < b[0]) {
            return {INT_MAX, INT_MIN};
        } 
        if (a[1] < b[1]) {
            return {b[0], a[1]};            
        }
        return b;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> points{{10,16},{2,8},{1,6},{7,12}};
    cout << s.findMinArrowShots(points) << endl;
}