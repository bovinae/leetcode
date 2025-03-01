/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

#include "leetcode.h"

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ret = new Node(0);
        Node* curr = ret;
        unordered_map<Node*, Node*> map;

        Node* tmp = head;
        while (head != nullptr) {
            curr->next = new Node(head->val);
            map[head] = curr->next;
            curr = curr->next;
            head = head->next;
        }

        head = tmp;
        curr = ret->next;
        while (head != nullptr) {
            curr->random = map[head->random];
            head = head->next;
            curr = curr->next;
        }

        return ret->next;
    }
};
// @lc code=end

