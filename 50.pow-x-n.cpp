/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
    2*2=4 10-2=8
    4*4=16 8-2=6
    16*16=256 6-4=2
    */
    double myPow1(double x, int n) {
        if (n == 0) return 1;
        if (abs(x - 1) <= 0.000001) return x;
        if (abs(x + 1) <= 0.000001) {
            if (n > 0) return x;
            return -x;
        }
        if (n == -2147483648) return 0;
        if (n < 0) return 1 / myPow(x, -n);

        int i = 1;
        double ret = x;
        // unordered_map<int, double> m;
        // m[1] = x;
        while (i <= n/2) {
            ret *= ret;    
            i *= 2;
        }
        
        if (i == n) return ret;
        return ret * myPow(x, n - i);
    }

    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (abs(x - 1) <= 0.000001) return x;
        if (abs(x + 1) <= 0.000001) {
            if (n > 0) return x;
            return -x;
        }
        if (n == -2147483648) return 0;
        
        int exponent = n;
        if (n < 0) exponent = -n;

        double res = 1.0;
        double pow = x;
        while (exponent != 0) {
            // 遇到bit 1，就把pow里面的值乘到res
            // eg: 二进制1010，相当于把x的10次幂拆成x的2次幂成x的8次幂。
            if ((exponent & 1) == 1) res *= pow;
            pow *= pow;
            exponent >>= 1;
        }

        return n < 0 ? 1 / res : res;
    }
};
// @lc code=end

