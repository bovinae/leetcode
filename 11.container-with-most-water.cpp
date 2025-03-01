/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        if (height.size() <= 1) return 0;

        int l = 0, r = height.size() - 1;
        int max_val = 0;
        int max_l = height[l], max_r = height[r];
        while (l < r) {
            if (height[l] < height[r]) {
                max_val = max(max_val, height[l] * (r - l));
                l++;
                while (l < r && height[l] <= max_l) l++;
                max_l = height[l];
            } else {
                max_val = max(max_val, height[r] * (r - l));
                r--;
                while (l < r && height[r] <= max_r) r--;
                max_r = height[r];
            }
        }
        return max_val;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> height{10,9,8,7,6,5,4,3,2,1};
    cout << s.maxArea(height) << endl;
}
