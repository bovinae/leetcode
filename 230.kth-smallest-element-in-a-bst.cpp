/*
 * @lc app=leetcode id=230 lang=cpp
 *
 * [230] Kth Smallest Element in a BST
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
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;
        int found = -1;
        inorderTraversal(root, k, i, found);
        return found;
    }

private:
    void inorderTraversal(TreeNode* root, int k, int& i, int& found) {
        if (found != -1) return ;
        if (root == nullptr) return ;

        inorderTraversal(root->left, k, i, found);
        if (++i == k) {
            found = root->val;
            return ;
        }
        inorderTraversal(root->right, k, i, found);
    }
};
// @lc code=end

