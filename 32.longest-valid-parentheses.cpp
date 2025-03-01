/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        // using stack
        int max_len = 0;
        stack<int> st;
        // 预置一个分割点
        st.push(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                // 记录index就可以算出长度
                st.push(i);
                continue;
            }

            // s[i] == ')'
            st.pop();
            // 留一个分割点
            if (st.empty()) st.push(i);
            else max_len = max(max_len, i - st.top()); 
        }
        return max_len;
    }
};
// @lc code=end
