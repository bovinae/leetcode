/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Node {
public:
    ListNode* n;
    int i;

    Node(ListNode* _n, int _i) : n(_n), i(_i) {}   
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr) {
                Node *node = new Node(lists[i], i);
                _heap.emplace_back(node);
                lists[i] = lists[i]->next;
            }
        }    
        if(_heap.empty()) return nullptr;
        build_heap();

        Node* node = pop();
        ListNode* root = node->n;
        ListNode* pre = root;
        int cur = node->i;
        while(true) {
            if(lists[cur] != nullptr) {
                push(new Node(lists[cur], cur));
                lists[cur] = lists[cur]->next;
            }
            node = pop();
            if(node == nullptr) {
                return root;
            }
            pre->next = node->n;
            pre = node->n;
            cur = node->i;
        };

        return root;
    }

private:
    void build_heap() {
        for(int i = _heap.size() / 2 - 1; i >= 0; i--) {
            heapify(i);
        }       
    }
    void heapify(int i) {
        int l = 2 * i + 1, r = l + 1;
        if(l >= _heap.size()) return;

        int v = _heap[i]->n->val;
        int lv = _heap[l]->n->val;
        int rv = (r < _heap.size()) ? _heap[r]->n->val : INT_MAX;
        if(lv < rv) {
            if(v <= lv) {
                return ;
            }
            swap(_heap[i], _heap[l]);
            heapify(l);
        } else {
            if(v <= rv) {
                return ;
            }
            swap(_heap[i], _heap[r]);
            heapify(r);
        }
    }
    void push(Node* n) {
        int i = 0;
        while(i < _heap.size()) {
            if(n->n->val < _heap[i]->n->val) swap(n, _heap[i]);
            int l = 2 * i + 1, r = l + 1;
            if(l >= _heap.size()) {
                _heap.push_back(n);
                return;
            }
            if(n->n->val < _heap[l]->n->val) {
                swap(n, _heap[l]);
                i = l;
                continue;
            }
            if(r >= _heap.size()) {
                _heap.push_back(n);
                return;
            } 
            if(n->n->val < _heap[r]->n->val) {
                swap(n, _heap[r]);
            }
            i = r;
        }
    }
    Node* pop() {
        if (_heap.empty()) return nullptr;
        Node* ret = _heap[0];
        swap(_heap[0], _heap[_heap.size() - 1]);
        _heap.pop_back();
        heapify(0);
        return ret;
    }
    vector<Node*> _heap; 
};
// @lc code=end
