/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<vector<char>> chars;
        for (int i = 0; i < digits.size(); i++) {
            chars.push_back(getChars(digits[i]));
        }

        vector<string> ans;
        string tmp = "";
        dfs(chars, 0, ans, tmp);        
        return ans;
    }

private:
    void dfs(vector<vector<char>>& chars, int i, vector<string>& ans, string& tmp) {
        if (i >= chars.size()) {
            ans.push_back(tmp);
            return ;
        }

        for (int j = 0; j < chars[i].size(); j++) {
            tmp.push_back(chars[i][j]);
            dfs(chars, i+1, ans, tmp);
            tmp.pop_back();            
        }       
    }

    vector<char> getChars(char c) {
        if ('2' <= c && c < '7') {
            vector<char> chars;
            for (int i = 0; i < 3; i++) {
                chars.push_back('a' + 3 * (c - '2') + i);
            }
            return chars;
        }

        if (c == '7') return {'p', 'q', 'r', 's'};
        if (c == '8') return {'t', 'u', 'v'};
        if (c == '9') return {'w', 'x', 'y', 'z'};
        return {};
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<string> ans = s.letterCombinations("23");
    for (auto &&a : ans) cout << a << " ";
    cout << endl;
}
