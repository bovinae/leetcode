/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) return {};

        vector<vector<int>> ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            tmp.reserve(n);
            for (int i = 0; i < n; i++) {
                TreeNode* f = q.front();
                q.pop();    
                tmp.push_back(f->val);
                if (f->left != nullptr) q.push(f->left);
                if (f->right != nullptr) q.push(f->right);
            }
            ret.push_back(tmp);
        }

        int n = ret.size();
        for (int i = 0; i < n/2; i++) {
            vector<int> tmp = ret[i];
            ret[i] = ret[n-i-1];
            ret[n-i-1] = tmp;
        }

        return ret;
    }
};
// @lc code=end

