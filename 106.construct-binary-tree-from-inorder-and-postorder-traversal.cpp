/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
        Input: inorder = [9,8, 3, 15,20,7], postorder = [8,9, 15,7,20, 3]
        Output: [3,9,20,null,null,15,7]
        2 1     2 1
     */
    // according to postorder root node from right to left, find root node in inorder to divide left subtree and right subtree
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return recursiveBuildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

    TreeNode* recursiveBuildTree(vector<int>& inorder, int il, int ir, vector<int>& postorder, int pl, int pr) {
        if (il > ir) return nullptr;
        if (il == ir) {
            return new TreeNode(inorder[il]);
        }

        TreeNode* root = new TreeNode(postorder[pr]);
        int i;
        for (i = il; i <= ir; i++) {
            if (inorder[i] == root->val) break;
        }
        /* 
            1. According to inorder left and right subtree size, calculate postorder left and right tree boundary.
            2. Here we need not to check whether index is out of bounds, because after we call the recursiveBuildTree, 
        at the beginning of recursiveBuildTree, we will check whether index is out of bounds.
        */
        root->right = recursiveBuildTree(inorder, i+1, ir, postorder, pl+i-il, pr-1);
        root->left = recursiveBuildTree(inorder, il, i-1, postorder, pl, pl+i-il-1);

        return root;
    }
};
// @lc code=end

