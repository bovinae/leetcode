/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

#include "leetcode.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* root = nullptr;
        ListNode* curr;
        while (l1 != nullptr && l2 != nullptr) {
            int tmp = l1->val + l2->val + carry;
            carry = tmp / 10;
            if (root == nullptr) {
                root = new ListNode(tmp % 10);
                curr = root;
            } else {
                curr->next = new ListNode(tmp % 10);
                curr = curr->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
            int tmp = l1->val + carry;
            carry = tmp / 10;
            if (root == nullptr) {
                root = new ListNode(tmp % 10);
                curr = root;
            } else {
                curr->next = new ListNode(tmp % 10);
                curr = curr->next;
            }
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            int tmp = l2->val + carry;
            carry = tmp / 10;
            if (root == nullptr) {
                root = new ListNode(tmp % 10);
                curr = root;
            } else {
                curr->next = new ListNode(tmp % 10);
                curr = curr->next;
            }
            l2 = l2->next;
        }
        if (carry > 0) {
            curr->next = new ListNode(carry);
        }
        return root;
    }
};
// @lc code=end

int main() {
    ListNode* l1 = new ListNode(9);
    for (int i = 0; i < 6; i++) {
        l1 = new ListNode(9, l1);
    }

    ListNode* l2 = new ListNode(9);
    for (int i = 0; i < 3; i++) {
        l2 = new ListNode(9, l2);
    }

    Solution s;
    ListNode* ret = s.addTwoNumbers(l1, l2);
    while (ret != nullptr) {
        cout << ret->val << " ";
        ret = ret->next;
    }
    cout << endl;
}
