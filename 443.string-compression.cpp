/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start
class Solution {
public:
    // ["a","a","b","b","c","c","c"]
    int compress(vector<char>& chars) {
        if (chars.size() <= 1) return chars.size();

        int w = 0;
        int n = 1;
        char c = chars[0];
        for (int i = 1; i < chars.size(); i++) {
            if (c == chars[i]) {
                n++;
                continue;
            }

            chars[w++] = c;
            if (n != 1) {
                string str = to_string(n);
                for (int i = 0; i < str.size(); i++) {
                    chars[w++] = str[i];
                }
            }
            n = 1;
            c = chars[i];            
        }
        chars[w++] = c;
        if (n != 1) {
            string str = to_string(n);
            for (int i = 0; i < str.size(); i++) {
                chars[w++] = str[i];
            }
        }

        return w;
    }
};
// @lc code=end
