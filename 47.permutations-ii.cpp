/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums, 0);
        return ret;
    }
    void dfs(vector<int>& nums, int i) {
        if(i == nums.size() - 1) {
            ret.emplace_back(nums);
            return;
        }

        /* eg: 1 1 2
            / 1 - 2
         1
            \ 2 - 1
            / 1 - 1
         2 
            \ 1 - 1 (Because current number 1 is equal to previous fixed number 1, so we should continue.)
         Note:
         Can be understood as: number in nums [0, i] is fixed, we swap i with [i, nums.size()-1].
         Before swap, check if current number is equal to previous fixed number, if so continue; else swap.
         Set which stores previous fixed number shouble be in function, not class member. Because we depend on it to auto release after function return.
         */
        set<int> st;
        for(int j = i; j < nums.size(); j++) {
            if(st.find(nums[j]) != st.end()) continue;
            st.insert(nums[j]);
            swap(nums[i], nums[j]);
            dfs(nums, i+1);
            swap(nums[i], nums[j]);
        }
    }
    vector<vector<int>> ret;
};
// @lc code=end

