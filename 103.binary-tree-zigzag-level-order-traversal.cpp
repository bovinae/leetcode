/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (root == nullptr) return ret;

        bool flag = true; // walk from left to right
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp(n, 0);
            for (int i = 0; i < n; i++) {
                TreeNode* tn = q.front();
                q.pop();
                if (flag) {
                    tmp[i] = tn->val;
                } else {
                    tmp[n-i-1] = tn->val;
                }
                if (tn->left != nullptr) q.push(tn->left);
                if (tn->right != nullptr) q.push(tn->right);
            }
            flag = !flag;
            ret.emplace_back(tmp);
        }
        return ret;
    }
};
// @lc code=end

