/*
 * @lc app=leetcode id=722 lang=cpp
 *
 * [722] Remove Comments
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ret;
        int mode = 0; // whether multi line mode
        string tmp = "";
        for (auto &&s : source) {
            if (s.size() == 0) continue;
            if (s.size() == 1) {
                ret.push_back(s);
                continue;
            }

            int pre = 0; // pre pos for recording
            int i;
            for (i = 1; i < s.size(); i++) {  
                if (mode == 1) {
                    // find "*/"
                    if (s[i-1] == '*' && s[i] == '/') {
                        mode = 0;
                        pre = i + 1;
                        i++;
                    }
                    continue;                    
                }   

                if (s[i-1] == '/' && s[i] == '/') {
                    tmp += s.substr(pre, i-1-pre);
                    pre = s.size();
                    break;
                }
                if (s[i-1] == '/' && s[i] == '*') {
                    mode = 1;
                    tmp += s.substr(pre, i-1-pre);
                    i++;
                }
            }
            if (mode == 0) {
                if (i > s.size()) i = s.size();
                if (pre < i) {
                    tmp += s.substr(pre, i - pre);
                }
                if (tmp.size() > 0) {
                    ret.push_back(tmp);
                    tmp = "";
                }                
            }
        }
        return ret;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<string> source = {"a/*/b//*c","blank","d*//e*//f"};
    vector<string> ret = s.removeComments(source);
    return 0;
}
