class TrieNode {
public:
    TrieNode *children[26];
    bool isWord;

    TrieNode() {
        for (auto &c : children) { c = nullptr; }
        isWord = false;
    }
};

class Trie {
private:
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    void addWord(string s) {
        TrieNode *tn = root;
        for (auto &c : s) {
            if (!tn->children[c - 'a']) {
                tn->children[c - 'a'] = new TrieNode();
            }
            tn = tn->children[c - 'a'];
        }
        tn->isWord = true;
    }

    TrieNode *getRoot() {
        return root;
    }
};

class Solution {
private:
    void dfs(vector<vector<char>> &board, vector<string> &res, int i, int j, TrieNode *root, string word) {
        char c = board[i][j];
        if (c == '#') { return; }

        root = root->children[c - 'a'];
        if (!root) { return; }
        
        word += c;
        if (root->isWord) {
            res.push_back(word);
            root->isWord = false;
        }

        board[i][j] = '#';
        if (i + 1 < board.size()) { dfs(board, res, i + 1, j, root, word); }
        if (i - 1 >= 0) { dfs(board, res, i - 1, j, root, word); }
        if (j + 1 < board[0].size()) { dfs(board, res, i, j + 1, root, word); }
        if (j - 1 >= 0) { dfs(board, res, i, j - 1, root, word); }
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie myTrie;
        for (auto &word : words) {
            myTrie.addWord(word);
        }

        vector<string> res;
        TrieNode *root = myTrie.getRoot();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, res, i, j, root, "");
            }
        }

        return res;
    }
};