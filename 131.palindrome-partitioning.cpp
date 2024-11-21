/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    // "aabcdcd"
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> res;
        bt(s, 0, curr, res);
        return res;
    }

    void bt(string s, int i, vector<string>& curr, vector<vector<string>>& res) {
        if (i == s.size()) {
            res.push_back(curr);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            if (isPalindrome(s, i, j)) {
                curr.push_back(s.substr(i, j - i + 1));
                bt(s, j + 1, curr, res);
                curr.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
// @lc code=end

int main() {
    Solution s;    
    auto res = s.partition("aabcdcd");
    for (auto& i : res) {
        for (auto& j : i) {
            cout << j << "\t";
        }
        cout << endl;
    }
    return 0;
}