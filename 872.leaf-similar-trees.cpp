/*
 * @lc app=leetcode id=872 lang=cpp
 *
 * [872] Leaf-Similar Trees
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> ret1;
        vector<int> ret2;
        dfs(root1, ret1);
        dfs(root2, ret2);
        if (ret1.size() != ret2.size()) return false;
        for (int i = 0; i < ret1.size(); i++) {
            if (ret1[i] != ret2[i]) return false;
        }
        return true;
    }

private:
    void dfs(TreeNode* root, vector<int>& ret) {
        if (root == nullptr) return ;
        if (root->left == nullptr && root->right == nullptr) {
            ret.push_back(root->val);
            return ;
        }

        dfs(root->left, ret);
        dfs(root->right, ret);
    }
};
// @lc code=end

