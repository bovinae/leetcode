/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26, 0);
        vector<int> m(26, -1);

        for (int i = 0; i < s.size(); i++) {
            int j = s[i] - 'a';
            v[j] ++;
            if (v[j] > 1) m[j] = -1;
            else m[j] = i;
        }

        int pos = INT_MAX;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] == 1) {
                pos = min(pos, m[i]);
            }
        }

        return (pos == INT_MAX) ? -1 : pos;
    }
};
// @lc code=end

