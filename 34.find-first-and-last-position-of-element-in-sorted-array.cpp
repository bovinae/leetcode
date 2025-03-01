/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    // 5,7,7,8,8,10
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return {-1, -1};
        vector<int> ret;
        int pos = findLeft(nums, target);
        ret.push_back(pos);
        pos = findRight(nums, target);
        ret.push_back(pos);
        return ret;
    }

private:
    int findLeft(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (target < nums[m]) r = m - 1;
            else if (nums[m] < target) l = m + 1;
            else r = m;
            if (r < 0 || l >= nums.size()) return -1;
        }
        
        return nums[l] == target ? l : -1;
    }

    int findRight(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r + 1) / 2;
            if (target < nums[m]) r = m - 1;
            else if (nums[m] < target) l = m + 1;
            else l = m;
            if (r < 0 || l >= nums.size()) return -1;
        }
        
        return nums[l] == target ? l : -1;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{2,2};
    vector<int> ret = s.searchRange(nums, 3);
    for (auto &&i : ret) cout << i << " ";
    cout << endl;
}
