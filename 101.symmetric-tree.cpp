/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
 */

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

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    /*
                  1
            2          2
          3    4     4   3
        5  6            6  5
     */
    // bfs: fill many nullptr and consume much time and memory
    bool isSymmetric1(TreeNode* root) {
        if (root == nullptr) return true;

        vector<TreeNode*> q{root};
        while (true) {
            bool last = true;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                if (q[i] == nullptr) {
                    q.emplace_back(nullptr);
                    q.emplace_back(nullptr);
                    continue;
                }
                q.emplace_back(q[i]->left);
                q.emplace_back(q[i]->right);
                last = false;
            }
            if (last) return true;

            q.erase(q.begin(), q.begin() + n);
            q.shrink_to_fit();
            for (int i = 0; i < q.size()/2; i++) {
                TreeNode *tmp1 = q[i];
                TreeNode *tmp2 = q[q.size() - i - 1];
                if (tmp1 == nullptr) {
                    if (tmp2 == nullptr) continue;
                    return false;
                }
                if (tmp2 == nullptr) return false;
                if (tmp1->val != tmp2->val) return false;
            }
        }
        return true;
    }

    // recursion
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;

        return recurse(root->left, root->right);
    }

private:
    bool recurse(TreeNode* l, TreeNode* r) {
        if (l == nullptr && r == nullptr) return true;
        if (l == nullptr || r == nullptr || l->val != r->val) return false;

        return recurse(l->left, r->right) && recurse(l->right, r->left);
    }
};
// @lc code=end

