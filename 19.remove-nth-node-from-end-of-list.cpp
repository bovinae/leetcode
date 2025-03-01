/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        for (int i = 0; i < n && head != nullptr; i++) {
            head = head->next;
        }
        // delete head node
        if (head == nullptr) {
            return tmp->next;
        }

        ListNode* pre = tmp;
        while (head->next != nullptr) {
            pre = pre->next;
            head = head->next;
        }

        // pre->b->c, have pre and delete b
        pre->next = pre->next->next;

        return tmp;
    }
};
// @lc code=end

