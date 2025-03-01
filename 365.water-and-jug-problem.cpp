/*
 * @lc app=leetcode id=365 lang=cpp
 *
 * [365] Water and Jug Problem
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x + y < z) return false;
        if (x + y == z || x == z || y == z) return true;
        if (x == y) return false;

        if (x < y) return dfs(y, x, z, 0);
        return dfs(x, y, z, 0);
    }
    // s is remaining water
    bool dfs(int x, int y, int z, int s) {
        if (s == y) return false;
        if (x + s == z || y + s == z || x - s == z || y - s == z) return true;

        if (s > y) {
            return dfs(x, y, z, s-y);
        }

        int tmp = x - (y - s);
        if (tmp == z) return true;
        return dfs(x, y, z, tmp);
    }

    bool canMeasureWater1(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity)
            return false;
        if (jug1Capacity == targetCapacity || jug2Capacity == targetCapacity || jug1Capacity + jug2Capacity == targetCapacity)
            return true;

        // get GCD, then we can use the property of Bézout's identity
        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }

private:
    // gcd(a, b) == gcd(b, a%b)
    int gcd(int a, int b) {
        while (b != 0) {
            int tmp = b;
            b = a % b;
            a =  tmp;
        }
        return a;
    }
};
// @lc code=end

int main() {
    Solution s;
    cout << s.canMeasureWater(3, 3, 5) << endl;
}
