/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    // 1->2->3->4->5->6, k=2
    // 2->1  3->4->5->6
    ListNode* reverseKGroup(ListNode* head, int k) {
        int i = 0;
        ListNode *cur = head, *pre = nullptr;
        while(cur != nullptr && i < k) {
            pre = cur;
            cur = cur->next;
            i++;
        }
        if(i < k) return head;
        pre ->next = nullptr;
        ListNode *new_head = reverseList(head);
        head->next = reverseKGroup(cur, k);
        return new_head;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *new_head = nullptr;
        while(cur != nullptr && cur->next != nullptr) {
            ListNode *post = cur->next;
            cur->next = new_head;
            new_head = cur;
            cur = post;
        }
        if(cur != nullptr) {
            cur->next = new_head;
            new_head = cur;
        }
        return new_head;
    }
};
// @lc code=end

