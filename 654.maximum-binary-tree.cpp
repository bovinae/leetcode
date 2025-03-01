/*
 * @lc app=leetcode id=654 lang=cpp
 *
 * [654] Maximum Binary Tree
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return recursive(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* recursive(vector<int>& nums, int i, int j) {
        if (i > j) return nullptr;
        if (i == j) {
            return new TreeNode(nums[i]);
        }

        int mPos = -1;
        int mVal = INT_MIN;
        for (int k = i; k <= j; k++) {
            if (nums[k] > mVal) {
                mVal = nums[k];
                mPos = k;
            }
        }
        TreeNode *node = new TreeNode(mVal);
        node->left = recursive(nums, i, mPos - 1);
        node->right = recursive(nums, mPos + 1, j);
        return node;
    }
};
// @lc code=end

