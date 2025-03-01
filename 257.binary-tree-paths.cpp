/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) return {to_string(root->val)};

        vector<string> ret;
        ret.reserve(100);
        dfs(root->left, ret, to_string(root->val));
        dfs(root->right, ret, to_string(root->val));
        ret.resize(ret.size());
        return ret;
    }

private:
    void dfs(TreeNode* root, vector<string>& ret, string tmp) {
        if(root == nullptr) return ;

        tmp += "->" + to_string(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            ret.push_back(tmp);
            return ;
        }

        dfs(root->left, ret, tmp);
        dfs(root->right, ret, tmp);
    }
};
// @lc code=end

