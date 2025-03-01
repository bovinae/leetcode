/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
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
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        dfs(root, 0, max_depth);
        return max_depth;
    }

private:
    void dfs(TreeNode* root, int depth, int& max_depth) {
        if (root == nullptr) {
            max_depth = max(max_depth, depth);
            return ;
        }

        depth++;
        dfs(root->left, depth, max_depth);
        dfs(root->right, depth, max_depth);
    }
};
// @lc code=end

