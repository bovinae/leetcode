/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 */

#include "leetcode.h"

// @lc code=start
class Trie {
public:
    /*
        dummy root node
    */
    Trie() {
        root = new Node(' ');
    }
    
    void insert(string word) {
        Node *curr = root;
        for (auto && c : word) {
            if (curr->next[c-'a'] == nullptr)
                curr->next[c-'a'] = new Node(c);
            curr = curr->next[c-'a'];
        }
        curr->is_word = true;
    }
    
    bool search(string word) {
        Node *curr = root;
        for (auto && c : word) {
            if (curr->next[c-'a'] == nullptr) return false;
            curr = curr->next[c-'a'];
        }
        if (curr->is_word) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node *curr = root;
        for (auto && c : prefix) {
            if (curr->next[c-'a'] == nullptr) return false;
            curr = curr->next[c-'a'];
        }
        return true;
    }

private:
    struct Node{
        char c;
        Node* next[26];
        bool is_word;

        Node(char _c) : c(_c), is_word(false) {
            for (int i = 0; i < 26; i++) next[i] = nullptr;
        }
    };

    Node *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

