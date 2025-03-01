/*
 * @lc app=leetcode id=873 lang=cpp
 *
 * [873] Length of Longest Fibonacci Subsequence
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int N = arr.size();
        unordered_set<int> S(arr.begin(), arr.end());

        int ans = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j) {
                /* With the starting pair (arr[i], arr[j]),
                 * y represents the future expected value in
                 * the fibonacci subsequence, and x represents
                 * the most current value found. */
                int x = arr[j], y = arr[i] + arr[j];
                int length = 2;
                while (S.find(y) != S.end()) {
                    int z = x + y;
                    x = y;
                    y = z;
                    ans = max(ans, ++length);
                }
            }

        return ans >= 3 ? ans : 0;
    }
};
// @lc code=end

