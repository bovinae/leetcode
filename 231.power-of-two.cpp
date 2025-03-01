/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        if (n == -pow(2, 31)) return false;

        return !(n & (n-1));
    }
};
// @lc code=end

int main() {
    map<int, int> m;
    m.insert(make_pair(1, 2));
    m.insert(make_pair(1, 3));
    m.insert(make_pair(1, 2));
    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
