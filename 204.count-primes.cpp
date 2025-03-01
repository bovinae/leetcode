/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    /*
    n=10
    2*2=4 2*3=6 2*4=8
    3*3=9
    */
    int countPrimes(int n) {
        int ret = 0;
        vector<bool> not_prime(n, false);
        for (int i = 2; i < n; i++) {
            if (!not_prime[i]) ret++;
            for (long long j = i; j * i < n; j++) {
                not_prime[j * i] = true;
            }
        }
        return ret;
    }

    // Time Limit Exceeded
    int countPrimes1(int n) {
        int ret = 0;
        for (int i = 2; i < n; i++) {
            if(isPrime(i)) ret++;
        }
        return ret;
    }

private:
    bool isPrime(int n) {
        int m = sqrt(n);
        for (int i = 2; i <= m; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
};
// @lc code=end

