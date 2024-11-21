/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 */

#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

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
    bool isValidBST(TreeNode* root) {
        long long pre = LONG_MIN;
        return dfs(root, pre);
    }

    bool dfs(TreeNode* root, long long& pre) {
        if (root == nullptr) return true;
        bool left = dfs(root->left, pre);
        if (!left) return false;
        if (root->val <= pre) return false;
        pre = root->val;
        bool right = dfs(root->right, pre);
        return right;
    }
};
// @lc code=end

int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(1);
    cout << s.isValidBST(root) << endl;
    return 0;
}
