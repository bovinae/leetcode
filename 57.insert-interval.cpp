/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0) return {newInterval};

        int l = findIndex(intervals, newInterval[0]);
        int r = findIndex(intervals, newInterval[1]);

        // left boundary locate in blank area
        if (l < 0 || intervals[l][1] < newInterval[0]) {
            // insert into blank interval            
            if (r == l) {
                intervals.insert(intervals.begin() + l + 1, newInterval);
                return intervals;
            }

            // cross interval: l < r
            intervals[r][0] = newInterval[0];
            intervals[r][1] = max(intervals[r][1], newInterval[1]);
            intervals.erase(intervals.begin() + l + 1, intervals.begin() + r);
            return intervals;
        }

        // left boundary locate in interval
        intervals[r][0] = intervals[l][0];
        intervals[r][1] = max(intervals[r][1], newInterval[1]);
        intervals.erase(intervals.begin() + l, intervals.begin() + r);

        return intervals;
    }

private:
    int findIndex(vector<vector<int>>& intervals, int pos) {
        int l = 0, r = intervals.size() - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (pos < intervals[m][0]) r = m-1;
            else if (pos > intervals[m][0]) l = m;
            else return m;
        }
        return pos < intervals[l][0] ? l-1 : l;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> intervals{{1,3},{6,9}};
    vector<int> newInterval{2, 5};
    s.insert(intervals, newInterval);
    for (auto &&i : intervals) {
        for (auto &&j : i) cout << j << " ";
        cout << endl;
    }
}