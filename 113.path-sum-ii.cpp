/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        vector<int> tmp;
        dfs(root, targetSum, ret, tmp);
        return ret;
    }

private:
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>& ret, vector<int> tmp) {
        if (root == nullptr) {
            return ;
        }

        tmp.push_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (targetSum == 0) ret.push_back(tmp);
            return ;
        }
        
        dfs(root->left, targetSum, ret, tmp);
        dfs(root->right, targetSum, ret, tmp);
    }
};
// @lc code=end

