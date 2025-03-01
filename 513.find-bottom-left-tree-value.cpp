/*
 * @lc app=leetcode id=513 lang=cpp
 *
 * [513] Find Bottom Left Tree Value
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
    /*
        recursive and record height and bottom left node
    */
    
    Solution() : curr(0), h(0), bl(nullptr) {}

    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        curr++;
        findBottomLeftValue(root->left);
        findBottomLeftValue(root->right);
        if(curr > h) {
            h = curr;
            bl = root;
        }
        curr--;

        return bl->val;
    }

private:
    int curr;
    int h;
    TreeNode *bl;
};
// @lc code=end

