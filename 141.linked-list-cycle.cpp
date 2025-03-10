/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
 */

#include "leetcode.h"

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (slow != nullptr && fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
            if (fast == nullptr) return false;
            fast = fast->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
// @lc code=end

