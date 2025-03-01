/*
 * @lc app=leetcode id=165 lang=cpp
 *
 * [165] Compare Version Numbers
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i = 0, j = 0;
        int num1 = 0, num2 = 0;
        while (i < n1 || j < n2) {
            while (i < n1 && version1[i] != '.') {
                num1 = num1 * 10 + version1[i] - '0';
            }
            while (j < n2 && version2[j] != '.') {
                num2 = num2 * 10 + version2[j] - '0';
            }
            if (num1 < num2) return -1;
            if (num1 > num2) return 1;
            i++;
            j++;
            num1 = 0;
            num2 = 0;
        }
        return 0;
    }
};
// @lc code=end

