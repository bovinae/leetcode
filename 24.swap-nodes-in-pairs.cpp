/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    // r->a->b->c
    // ^cur
    ListNode* swapPairs(ListNode* head) {
        ListNode *cur = head, *pre = nullptr, *post = nullptr;
        while(cur != nullptr && cur->next != nullptr) {
            post = cur->next->next;
            cur->next->next = cur;
            if(pre == nullptr) {
                head = cur->next;
            } else {
                pre->next = cur->next;
            }
            cur->next = post;
            pre = cur;
            cur = post;
        }
        return head;
    }
};
// @lc code=end
