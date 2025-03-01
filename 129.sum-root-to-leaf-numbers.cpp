/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        dfs(root, sum, 0);
        return sum;
    }

private:
    void dfs(TreeNode* root, int& sum, int tmp) {
        if (root == nullptr) return ;

        tmp = tmp * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) sum += tmp;
        dfs(root->left, sum, tmp);
        dfs(root->right, sum, tmp);
    }
};
// @lc code=end

