/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret;
        for (int i = 0; i < n; i++) {
            ret.push_back(vector<int>(n, 0));
        }
        int a = 0, b = n-1, c = 0, d = n-1;
        int counter = 1;
        while (a <= b && c <= d) {
            for (int i = a; i <= b; i++) {
                ret[c][i] = counter++;
            }
            c++;
            for (int i = c; i <= d; i++) {
                ret[i][b] = counter++;
            }
            b--;
            for (int i = b; i >= a; i--) {
                ret[d][i] = counter++;
            }
            d--;
            for (int i = d; i >= c; i--) {
                ret[i][a] = counter++;
            }
            a++;
        }
        return ret;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<int>> ret = s.generateMatrix(3);
    for (auto &&i : ret) {
        for (auto &&j : i) cout << j << " ";
        cout << endl;
    }
}
