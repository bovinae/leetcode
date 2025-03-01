/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    void Init(void) {
        _map['I'] = 1;
        _map['V'] = 5;
        _map['X'] = 10;
        _map['L'] = 50;
        _map['C'] = 100;
        _map['D'] = 500;
        _map['M'] = 1000;
    }

    int romanToInt(string s) {
        if (s.size() == 0) return 0;

        Init();
        
        int sum = 0;
        sum += _map[s[s.size() - 1]];
        for (int i = s.size() - 2; i >= 0; i--) {
            if (_map[s[i]] < _map[s[i + 1]]) sum -= _map[s[i]];
            else sum += _map[s[i]];
        }
        return sum;
    }

private:
    unordered_map<char, int> _map;
};
// @lc code=end
