/*
 * @lc app=leetcode id=526 lang=cpp
 *
 * [526] Beautiful Arrangement
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
    1 2 3 4
    1 4 3 2
    3 2 1 4
    3 4 1 2
    */
    int countArrangement(int n) {
        vector<int> nums;
        for (int i = 1; i <= n; i++) nums.push_back(i);
        int count = 0;
        dfs(nums, 0, count);
        return count;
    }

private:
    void dfs(vector<int>& nums, int i, int& count) {
        if (i == nums.size()) {
            count++;
            return ;
        }

        for (int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            // 只校验换入数字是否满足条件。换出数字在后面的递归中会判断，不满足条件不会递归到终止条件。
            if (nums[i] % (i+1) == 0 || (i+1) % nums[i] == 0) dfs(nums, i+1, count);
            swap(nums[i], nums[j]);
        }
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.countArrangement(6) << endl;
}
