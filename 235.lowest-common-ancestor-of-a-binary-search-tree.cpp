/*
 * @lc app=leetcode id=235 lang=cpp
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
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
        // 让p是较小节点
        if (p->val > q->val) return lowestCommonAncestor(root, q, p);

        // 当前节点是较小节点，较大节点肯定在右子树。
        if (p->val == root->val) return root;

        if (p->val < root->val) {
            // 分布在root两侧或者当前节点就是q
            if (q->val >= root->val) return root;
            // p,q 都在左侧
            return lowestCommonAncestor(root->left, p, q);
        }

        // p,q 都在右侧
        return lowestCommonAncestor(root->right, p, q);
    }
};
// @lc code=end

