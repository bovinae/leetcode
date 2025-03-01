/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {
        int h = -1;
        TreeNode* p = root;
        while (p != nullptr) {
            h++;
            p = p->left;
        }

        int ret = 0;
        for (int i = 0; i <= h; i++) {
            ret += pow(2, i);
        }

        int mis = 0;
        bool over = false;
        dfs(root, h, -1, mis, over);
        return ret-mis;
    }

private:
    void dfs(TreeNode* root, int h, int cur, int& mis, bool& over) {
        if (over) return ;
        if (root == nullptr) {
            if (cur != h) mis++;
            else over = true;
            return ;
        }

        cur++;
        dfs(root->right, h, cur, mis, over);
        dfs(root->left, h, cur, mis, over);
    }
};
// @lc code=end

