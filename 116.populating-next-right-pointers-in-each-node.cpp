/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

#include "leetcode.h"

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // bfs
    Node* connect(Node* root) {
        if (root == nullptr) return root;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            Node* cur = q.front();
            q.pop();
            if (cur->left != nullptr) q.push(cur->left);
            if (cur->right != nullptr) q.push(cur->right);
            for (int i = 0; i < n-1; i++) {
                cur->next = q.front();
                q.pop();
                cur = cur->next;
                if (cur->left != nullptr) q.push(cur->left);
                if (cur->right != nullptr) q.push(cur->right);
            }
        }

        return root;
    }
};
// @lc code=end

