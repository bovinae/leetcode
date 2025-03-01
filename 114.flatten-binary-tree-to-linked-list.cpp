/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
        1. Iterate to find the predecessor node of the right subtree in the left subtree;
        2. Append the right subtree to the predecessor node;
        3. Set the right of the root to left;
        4. Set the left of the root to nullptr;
        5. Move the pointer to the root->right, and then go to 1 for looping.
     */
    void flatten(TreeNode* root) {
        while (root != nullptr) {
            if (root->left == nullptr) {
                root = root->right;
                continue;
            }

            TreeNode* cur = root->left;
            while (cur->right != nullptr) {
                cur = cur->right;
            }
            cur->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            root = root->right;
        }
    }
};
// @lc code=end

