/*
 * @lc app=leetcode id=226 lang=cpp
 *
 * [226] Invert Binary Tree
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
    TreeNode* invertTree(TreeNode* root) {
        recurse(root);
        return root;
    }

private:
    void recurse(TreeNode* root) {
        if (root == nullptr) return ;

        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        recurse(root->left);
        recurse(root->right);
    }
};
// @lc code=end

