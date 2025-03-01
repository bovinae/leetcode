/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

#include "leetcode.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    1 2 3
    */
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret = build(1, n);
        return ret;
    }

private:
    vector<TreeNode*> build(int begin, int end) {
        if (begin > end) return {nullptr};
        if (begin == end) return {new TreeNode(begin)};

        vector<TreeNode*> ret;
        ret.reserve(10 * (end - begin));
        for (int i = begin; i <= end; i++) {
            vector<TreeNode*> lefts = build(begin, i-1);
            vector<TreeNode*> rights = build(i+1, end);
            for (int j = 0; j < lefts.size(); j++) {
                for (int k = 0; k < rights.size(); k++) {
                    // 注意：每颗树都要生成单独的root。
                    TreeNode* root = new TreeNode(i);                    
                    root->left = lefts[j];
                    root->right = rights[k];
                    ret.push_back(root);
                }
            }
        }
        ret.resize(ret.size());
        return ret;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<TreeNode*> ret = s.generateTrees(3);
}