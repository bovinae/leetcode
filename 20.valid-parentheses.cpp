/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> map;
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';

        stack<char> tmp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
                tmp.push(s[i]);
            else if (!tmp.empty() && tmp.top() == map[s[i]]) 
                tmp.pop();
            else 
                return false;
        }

        return tmp.size() == 0;
    }
};
// @lc code=end

