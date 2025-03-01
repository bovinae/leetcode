/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    // dfs
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return max_path_sum;
    }

private:
    /*
        [5,4,8,11,null,13,4,7,2,null,null,null,1]
                        5
            4                       8
          11                   13       4
        7    2                             1

        [9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6]
                        9
            6                       -3
                            -6                 2
                                          2
                                      -6     -6
                                    -6
     */
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;

        // accumulate left and right max path sum (bilateral max path sum), and update the global max path sum: max_path_sum
        int l = dfs(root->left);
        int r = dfs(root->right);
        int tmp = root->val;
        if (l > 0) tmp += l;
        if (r > 0) tmp += r;
        if (tmp > max_path_sum) max_path_sum = tmp;

        // return value should be unilateral max path sum
        if (l < r) swap(l, r);
        if (l > 0)
            return root->val + l;
        return root->val;
    }

    int max_path_sum = INT_MIN;
};
// @lc code=end

