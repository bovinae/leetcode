/*
 * @lc app=leetcode id=445 lang=cpp
 *
 * [445] Add Two Numbers II
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
        ListNode* rl1 = revertList(l1);
        ListNode* rl2 = revertList(l2);
        int carry = 0;
        ListNode *pre_rl1 = nullptr;
        ListNode *tmp = rl1;
        while (rl1 != nullptr && rl2 != nullptr) {
            rl1->val += rl2->val + carry;
            carry = rl1->val / 10;
            rl1->val %= 10;
            pre_rl1 = rl1;            
            rl1 = rl1->next;
            rl2 = rl2->next;
        }
        if (rl2 != nullptr) {
            pre_rl1->next = rl2;
            rl1 = rl2;
        }
        while (rl1 != nullptr && carry != 0) {
            rl1->val += carry;
            carry = rl1->val / 10;
            rl1->val %= 10;
            pre_rl1 = rl1;            
            rl1 = rl1->next;
        }
        if (carry != 0) {
            ListNode *node = new ListNode(carry);
            pre_rl1->next = node;
        }
        return revertList(tmp);
    }

private:
    ListNode* revertList(ListNode *head) {
        ListNode *new_head = nullptr;
        while (head != nullptr) {
            ListNode *post = head->next;
            head->next = new_head;
            new_head = head;
            head = post;
        }
        return new_head;
    }
};
// @lc code=end

