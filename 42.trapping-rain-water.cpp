/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;

        int sum = 0;
        int left = 1, right = height.size() - 2;
        int max_left = height[0], max_right = height[right+1];
        while (left <= right) {
            if (max_left <= max_right) {
                if (height[left] >= max_left) {
                    max_left = height[left];
                } else {
                    sum += max_left - height[left];
                }
                left++;
            } else {
                if (height[right] >= max_right) {
                    max_right = height[right];
                } else {
                    sum += max_right - height[right];
                }
                right--;
            }
        }

        return sum;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> height{4,2,3};
    cout << s.trap(height) << endl;
}