/*
 * @lc app=leetcode id=273 lang=cpp
 *
 * [273] Integer to English Words
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";

        int i = 0;
        string word = "";
        while (num > 0) {
            if (num % 1000 != 0)
                word = helper(num % 1000) + thousands[i] + " " + word;
            num /= 1000;
            i++;
        }

        rtrim(word);
        return word;
    }

private:
    vector<string> less_than_20{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> thousands{"", "Thousand", "Million", "Billion"};

    string helper(int n) {
        if (n == 0) return "";
        if (n < 20) return less_than_20[n] + " ";
        if (n < 100) return tens[n / 10] + " " + helper(n % 10);
        return helper(n / 100) + "Hundred " + helper(n % 100);
    }

    void rtrim(string &s) {
        s.erase(find_if(s.rbegin(), s.rend(), [](char c) {
            return !isspace(c);
        }).base(), s.end());
    }
};
// @lc code=end

