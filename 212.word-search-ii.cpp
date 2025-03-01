/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

#include "leetcode.h"

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        row = board.size();
        col = board[0].size();

        vector<string> ret;
        TrieNode* root = buildTrie(words);
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dfs(board, i, j, root, ret);
            }
        }
        return ret;
    }

private:
    int row;
    int col;

    struct TrieNode {
        TrieNode* next[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++) next[i] = nullptr;
            word = "";
        }
    };

    TrieNode* buildTrie(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto &&word : words) {
            TrieNode* p = root;            
            for (auto &&c : word) {
                int pos = c - 'a';
                if (p->next[pos] == nullptr) p->next[pos] = new TrieNode();
                p = p->next[pos];
            }
            p->word = word;
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root, vector<string> &ret) {
        char c = board[i][j];
        if (c == ' ' || root->next[c - 'a'] == nullptr) return ;
        root = root->next[c - 'a'];
        if (root->word != "") {
            ret.push_back(root->word);
            root->word = "";
        }
        
        board[i][j] = ' ';
        if (i > 0) dfs(board, i-1, j, root, ret);
        if (j > 0) dfs(board, i, j-1, root, ret);
        if (i < row-1) dfs(board, i+1, j, root, ret);
        if (j < col-1) dfs(board, i, j+1, root, ret);        
        board[i][j] = c;
    }
};
// @lc code=end

int main() {
    Solution s;
    vector<vector<char>> board = {
        {'o','a','a','n'},
        {'e','t','a','e'},
        {'i','h','k','r'},
        {'i','f','l','v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> results = s.findWords(board, words);
    for (auto &&result : results) {
        cout << result << endl;
    }
}
