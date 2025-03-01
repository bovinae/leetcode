/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

private:
    TreeNode* dfs(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
        if (pl > pr || il > ir) return nullptr;
        TreeNode* root = new TreeNode(preorder[pl]);
        if (pl == pr) {
            return root;
        }

        int i;
        for (i = il; i <= ir; i++) {
            if (inorder[i] == preorder[pl]) break;
        }
        root->left = dfs(preorder, pl+1, pl+i-il, inorder, il, i-1);
        root->right = dfs(preorder, pl+i-il+1, pr, inorder, i+1, ir);
        return root;
    }
};
// @lc code=end

