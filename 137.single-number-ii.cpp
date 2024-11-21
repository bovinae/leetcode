/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    // [-2,-2,1,1,4,1,4,4,-4,-2]
    int singleNumber(vector<int>& nums) {
        int target = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int j = 0; j < nums.size(); j++) {
                if ((nums[j] >> i) & 1) {
                    sum++;
                }
            }
            target |= (sum % 3) << i;
        }
        return target;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums = { -2,-2,1,1,4,1,4,4,-4,-2 };
    cout << s.singleNumber(nums) << endl;
    return 0;
}
