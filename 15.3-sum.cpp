/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // -4,-1,-1,0,1,2
        vector<vector<int>> ret;
        for (int i = 0; i < nums.size(); i++) {
            int t = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int tmp = nums[l] + nums[r];
                if (tmp > t) 
                    r--;
                else if (tmp < t)
                    l++;
                else {
                    ret.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    // process left
                    while(l+1 < r && nums[l] == nums[l+1]) l++;
                    l++;
                    // process right
                    while(r-1 > l && nums[r] == nums[r-1]) r--;
                    r--;
                }
            }  
            // process the first same number
            while (i+1 < nums.size() && nums[i] == nums[i+1]) i++;           
        }

        return ret;
    }
};
// @lc code=end

int main(int argc, char *argv[]) {
    Solution s;
    vector<int> nums{-4,-1,-1,0,1,2};
    s.threeSum(nums);
}