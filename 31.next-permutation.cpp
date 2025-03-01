/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
        1 2 3 5 7 6 4
              ^ ^
              | |second
              |first
        revert from second to end:
        1 2 3 5 4 6 7
              ^   ^
              |   |bigger than first, and then swap to get the result
              |first
        */
        if (nums.size() <= 1) return ;

        int n = nums.size();

        // find descending number pair from right to left        
        int first = n-2, second = n-1;
        while (first >= 0 && nums[first] >= nums[second]) {
            first--;
            second--;
        }

        // because numbers from second to last is descending, we need reverting the sequence to get the minimum order 
        int l = second, r = n-1;
        while (l < r) {
            swap(nums[l++], nums[r--]);
        }

        if (first == -1) return ;

        // find the next bigger number than first, and swap
        for (int i = second; i < n; i++) {
            if (nums[first] < nums[i]) {
                swap(nums[first], nums[i]);
                return ;
            }
        }
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums{1, 1, 5};
    s.nextPermutation(nums);
    for (auto && i : nums) {
        cout << i << " ";
    }
    cout << endl;
}
