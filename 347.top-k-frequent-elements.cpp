/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() <= 1) return nums;

        unordered_map<int, int> c;
        for (auto &&n : nums) c[n]++;
        
        vector<pair<int, int>> n;
        for (auto &&cc : c) {
            n.push_back(make_pair(cc.second, cc.first));
        }
        
        return partition(n, 0, n.size() - 1, k);
    }

private:
    vector<int> partition(vector<pair<int, int>> n, int l, int r, int k) {
        // 1 5 2 2 3 4 2 2

        // part
        int old_l = l;
        int old_r = r;
        while (l < r) {
            // 找第一个>=taget
            while (l < r && n[l].first < n[old_r].first) l++;
            // 找第一个<taget
            while (l < r && n[r].first >= n[old_r].first) r--;
            if (l >= r) break;
            // n[l]一定大于n[r]
            swap(n[l], n[r]);
        }
        // now l is the partition point
        int p = l;
        swap(n[p], n[old_r]);

        int right_len = old_r - p + 1;
        if(k == right_len) {
            vector<int> ans;
            for (int i = p; i < n.size(); i++) {
                ans.emplace_back(n[i].second);
            }
            return ans;
        }

        if (k < right_len) return partition(n, p+1, old_r, k);
        // k > right_len
        return partition(n, old_l, p-1, k-right_len);
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> ans = s.topKFrequent(nums, 2);
    for (auto &&a : ans) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
