/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    // nums = [4,5,6,7,0,1,2], target = 0
    int search(vector<int>& nums, int target) {
        int rotatePoint = getRotatePoint(nums);
        int left = rotatePoint, right = rotatePoint + nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid % nums.size()] == target) {
                return mid % nums.size();
            } else if (nums[mid % nums.size()] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }

    int getRotatePoint(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    cout << s.search(nums, 0) << endl;
    return 0;
}
