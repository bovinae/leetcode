/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        
        dfs(root, 0);
        return ret;
    }

private:
    int ret = INT_MAX;
    void dfs(TreeNode* root, int depth) {
        if (root == nullptr) {
            return ;
        }

        depth++;
        if (root->left == nullptr && root->right == nullptr) {
            ret = min(ret, depth);
        }
        dfs(root->left, depth);
        dfs(root->right, depth);
    }
};
// @lc code=end

