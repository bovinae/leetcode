/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> tmp;
        bt(s, 0, 0, ret, tmp);
        return ret;
    }

private:
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void bt(string& s, int i, int j, vector<vector<string>>& ret, vector<string>& tmp) {
        if (j >= s.size()) {
            if (i >= s.size()) ret.push_back(tmp);
            return ;
        }

        if (isPalindrome(s, i, j)) {
            tmp.push_back(s.substr(i, j-i+1));
            bt(s, j+1, j+1, ret, tmp);
            tmp.pop_back();
        }
        
        // 1、当前非回文；2、当前是回文，回溯后，右指针继续往右移。
        bt(s, i, j+1, ret, tmp);
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<string>> ret = s.partition("aab");
    for (auto &&i : ret) {
        for (auto &&j : i) cout << j << " ";
        cout << endl;
    }
}
