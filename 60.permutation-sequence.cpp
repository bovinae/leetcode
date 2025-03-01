/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> digits(n, 0);
        // not use index 0
        vector<int> count(n+1, 1);
        for (int i = 1; i <= n; i++) {
            digits[i-1] = '0' + i;
            count[i] = i * count[i - 1];
        }

        string ret;
        // begin from 0, so k-1
        recurse(n, k-1, count, digits, ret);
        return ret;
    }

private:
    void recurse(int n, int k, vector<int>& count, vector<char>& digits, string& ret) {
        if (k == 0) {
            // just append digits to the ret string
            ret += digits.data();
            return ;
        }

        int c = count[n-1];
        int i = k / c;
        ret += digits[i];
        digits.erase(digits.begin() + i);
        // exclude i*c permutations
        k -= i * c;

        // 31 21
        recurse(n-1, k, count, digits, ret);
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.getPermutation(3, 5) << endl;
}
