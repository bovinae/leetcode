/*
 * @lc app=leetcode id=672 lang=cpp
 *
 * [672] Bulb Switcher II
 */

// @lc code=start
class Solution {
public:
    /*
        1 + 2 --> 3, 1 + 3 --> 2, 2 + 3 --> 1
        So, there are only 8 cases.
        All_on, 1, 2, 3, 4, 1+4, 2+4, 3+4

        We only need to consider special cases which n<=2 and m <= 2. When n >= 3 and m >= 3, the result is 8.
    */
    int flipLights(int n, int presses) {
        if (n == 0) return 1;

        if (n == 1) {
            if (presses == 0) return 1;
            return 2;
        }

        if (n == 2) {
            if (presses == 0) return 1;
            if (presses == 1) return 3;
            return 4;
        }

        // n >= 3
        if (presses == 0) return 1;
        /*
        - [off, off, off] by pressing button 1
        - [off, on, off] by pressing button 2
        - [on, off, on] by pressing button 3
        - [off, on, on] by pressing button 4
        */
        if (presses == 1) return 4;
        /*
        [on, on, on] 1+1-->All_on
        [on, off, on] 1+2-->3
        [off, on, off] 1+3-->2
        [off, off, off] 2+3-->1
        [on, off, off] 1+4
        [on, on, off] 2+4
        [off, off, on] 3+4
        */
        if (presses == 2) return 7;
        return 8;
    }
};
// @lc code=end

