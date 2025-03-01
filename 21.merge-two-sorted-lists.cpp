/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* root = nullptr, *pre = nullptr;
        if(list1->val <= list2->val) {
            root = list1;
            list1 = list1->next;
        }else{
            root = list2;
            list2 = list2->next;
        }
        pre = root;
        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val <= list2->val){
                pre->next = list1;
                pre = list1;
                list1 = list1->next;
            }else{
                pre->next = list2;
                pre = list2;
                list2 = list2->next;
            }
        }

        if(list1 == nullptr) pre->next = list2;
        if(list2 == nullptr) pre->next = list1;
        return root;
    }
};
// @lc code=end

