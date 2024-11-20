#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return nullptr;
        }
        int len = 0;
        for (int i = lists.size() - 1; i >= 0; i--) {
            if (lists[i] != nullptr) {
                len = i + 1;
                break;
            }
        }
        for (int i = len - 1; i >= 0; i--)
        {
            if (lists[i] == nullptr) {
                lists[i] = lists[len - 1];
                len--;
            }
        }
        if (len == 0) return nullptr;
        lists.resize(len);

        ListNode* root = new ListNode();
        ListNode* curr = root;

        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
            };

        make_heap(lists.begin(), lists.end(), compare);
        while (lists.size() > 1) {
            pop_heap(lists.begin(), lists.end(), compare);
            curr->next = lists.back();
            curr = curr->next;
            lists.back() = lists.back()->next;
            if (lists.back() == nullptr) {
                lists.pop_back();
            }

            if (lists.size() > 0) {
                push_heap(lists.begin(), lists.end(), compare);
            }
        }

        if (lists.size() == 1) {
            curr->next = lists[0];
        }
        else {
            curr->next = nullptr;
        }

        return root->next;
    }

private:
    void printHeap(vector<ListNode*>& lists) {
        for (auto i : lists) {
            if (i == nullptr) {
                cout << "null\t";
            }
            else {
                cout << i->val << "\t";
            }
        }
        cout << endl;
    }
};

int main()
{
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(7);
    ListNode* l3 = new ListNode(3);
    l3->next = new ListNode(8);
    l3->next->next = new ListNode(9);
    vector<ListNode*> lists = { l1, l2, l3 };

    Solution s;
    auto root = s.mergeKLists(lists);
    while (root != nullptr) {
        cout << root->val << "\t";
        root = root->next;
    }
    cout << endl;
}
