/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        return dfs(root, 0) != -1;
    }

private:
    int dfs(TreeNode* root, int h) {
        if (root == nullptr) {
            return h;
        }

        h++;
        int left_h = dfs(root->left, h);
        if (left_h == -1) return -1;
        int right_h = dfs(root->right, h);
        if (right_h == -1) return -1;
        int delta = left_h - right_h;
        if (delta < -1 || 1 < delta) {
            return -1;
        }
        return max(left_h, right_h);
    }

public:
    int test_item_32()
    {
        std::vector<int> v;
        v.reserve(10);
        for (int i = 1; i <= 10; ++i) v.push_back(i);
        fprintf(stdout, "v.size: %d\n", v.size()); // 输出10
        v[3] = v[5] = v[9] = 99;
        std::remove(v.begin(), v.end(), 99); // 删除所有值等于99的元素
        fprintf(stdout, "v.size: %d\n", v.size()); // 仍然输出10, remove不是真正意义上的删除，因为它做不到
        for (auto i : v) fprintf(stdout, "%d\n", i);
    
        v.erase(std::remove(v.begin(), v.end(), 99), v.end()); // 真正删除所有值等于99的元素	
    
        return 0;
    }
};
// @lc code=end

int main() {
    Solution s;
    s.test_item_32();
}