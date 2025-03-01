/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
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
    void recoverTree(TreeNode* root) {
        pre = new TreeNode(INT_MIN);
        left = right = nullptr;

        walk(root);
        swap(left->val, right->val);
    }

private:
    TreeNode* pre;
    TreeNode* left;
    TreeNode* right;

    // middle-order
    void walk(TreeNode* root) {
        if (root == nullptr) return ;

        walk(root->left);
        if (pre->val > root->val) {
            if (left == nullptr) {
                left = pre;
                right = root;
            } else {
                right = root;
                return ;
            }
        }
        pre = root;
        walk(root->right);
    }
};
// @lc code=end

