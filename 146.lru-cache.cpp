/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

#include <unordered_map>

using namespace std;

// @lc code=start
class LRUCache {
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->pre = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) return -1;

        Node *node = cache[key];
        remove_node(node);
        add_to_head(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if (cache.count(key)) {
            Node *node = cache[key];
            node->val = value;
            remove_node(node);
            add_to_head(node);
            return ;
        }

        Node *node = new Node(key, value);
        add_to_head(node);
        cache[key] = node;
        if (cache.size() > capacity) {
            cache.erase(remove_tail());
        }
    }

private:
    struct Node {
        int key, val;
        Node *next;
        Node *pre;
        Node(int x, int y) : key(x), val(y), next(nullptr), pre(nullptr) {}
    };
    unordered_map<int, Node*> cache;
    Node *head, *tail;
    int capacity;

    void remove_node(Node *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
        node->pre = nullptr;
        node->next = nullptr;
    }

    void add_to_head(Node *node) {
        node->next = head->next;
        node->pre = head;
        head->next = node;
        node->next->pre = node;
    }

    int remove_tail() {
        Node *node = tail->pre;
        int ret = node->key;
        tail->pre->pre->next = tail;
        tail->pre = tail->pre->pre;
        delete node;
        return ret;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

