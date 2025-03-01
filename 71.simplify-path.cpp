/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        if (path.size() <= 1) return path;

        string ret{"/"};
        string pre = "";
        for (int i = 1; i < path.size(); i++) {
            if (ret.back() != '/') {
                ret.append(path, i, 1);
                continue;
            }

            switch (path[i]) {
            case '.':
                pre.append(path, i, 1);
                break;                
            case '/':
                if (pre == "..") {
                    size_t found = ret.rfind('/', ret.size() - 2);
                    if (found != string::npos) {
                        ret.replace(ret.begin() + found + 1, ret.end(), "");
                    }
                } else if (pre != "" && pre != ".") {
                    ret.append(pre + "/");
                }
                pre = "";
                break;
            default:
                if (pre != "") {
                    ret.append(pre);
                    pre = "";
                }
                ret.append(path, i, 1);
            };      
        }

        if (pre == "..") {
            size_t found = ret.rfind('/', ret.size() - 2);
            if (found != string::npos) {
                ret.replace(ret.begin() + found + 1, ret.end(), "");
            }
        } else if (pre != "" && pre != ".") {
            ret.append(pre);
        }
        if (ret.size() > 1 && ret.back() == '/') ret.pop_back();

        return ret;
    }
};
// @lc code=end

