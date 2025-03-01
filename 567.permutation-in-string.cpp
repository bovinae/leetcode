/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    // ab cdbad
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;

        vector<int> m(26, 0);
        int delta = 0;

        for (int i = 0; i < s1.size(); i++) {
            m[s1[i] - 'a']--;
            m[s2[i] - 'a']++; // input ++
        }
        for (auto &&c : m) {
            if (c != 0) delta++;
        }
        if (delta == 0) return true;

        for (int i = s1.size(); i < s2.size(); i++) {
            // x is output, y is input
            int x = s2[i-s1.size()] - 'a', y = s2[i] - 'a';
            if (x == y) continue;

            if (m[x] == 0) delta++;
            m[x]--; // output --
            if(m[x] == 0) delta--;

            if (m[y] == 0) delta++;
            m[y]++; // input ++
            if(m[y] == 0) delta--;

            if (delta == 0) return true;
        }
        return false;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.checkInclusion("ab", "eidbaooo") << endl;
    return 0;
}
