/*
 * @lc app=leetcode id=100 lang=cpp
 *
 * [100] Same Tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }

private:
    bool dfs(TreeNode* p, TreeNode* q) {
        if (p == nullptr) return q == nullptr;
        if (q == nullptr) return p == nullptr;
        if (p->val != q->val) return false;

        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }
};
// @lc code=end

