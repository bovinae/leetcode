/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict;
        for (int i = 0; i < wordDict.size(); i++) {
            dict.insert(wordDict[i]);
        }

        bool dp[s.size() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = i-1; j >= 0; j--) {
                if (dp[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};
// @lc code=end

