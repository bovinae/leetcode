/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

#include "leetcode.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);

        // found one node, 随着递归调用完成并返回，一直往上带。同时，如果有子节点是p或q，在这里就屏蔽了，直接返回父节点（p或q）。
        if (root == p || root == q) return root;

        // 随着递归调用完成并返回，往上带找到的p或q或lowest common ancestor
        if (l == nullptr) return r;
        if (r == nullptr) return l;

        // l != nullptr && r != nullptr, found, the root node is the lowest common ancestor
        return root;
    }
};
// @lc code=end

