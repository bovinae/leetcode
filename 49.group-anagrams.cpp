/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> results;
        for (auto &&str : strs) {
            int dict[26] {};
            for (int i = 0; i < str.size(); i++) {
                dict[str[i] - 'a']++;
            }
            string key{};
            for (int i = 0; i < 26; i++) {
                if (dict[i] == 0) continue;
                key += to_string(i) + "|" + to_string(dict[i]);
            }
            results[key].push_back(str);
        }

        vector<vector<string>> ans;
        for (auto it = results.begin(); it != results.end(); it++) {
            ans.push_back(it->second);
        }
        return ans;
    }

private:

};
// @lc code=end

int main() {
    Solution s;
    vector<string> strs{"bdddddddddd","bbbbbbbbbbc"};
    vector<vector<string>> ret = s.groupAnagrams(strs);
    for (auto &&r : ret) {
        for (auto &&er : r) {
            cout << er << " ";
        }
        cout << endl;
    }
}
