class TrieNode{
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};

class PrefixTree {
     TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();   
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(auto &c : word){
            if(cur->children[c - 'a'] == nullptr){
                cur->children[c - 'a'] = new TrieNode();
            }
            cur = cur->children[c - 'a'];
        }
        cur->endOfWord = true;
        
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(auto &c : word){
            if(cur->children[c - 'a'] == nullptr){
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->endOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(auto &c : prefix){
            if(cur->children[c - 'a'] == nullptr){
                return false;
            }
            cur = cur->children[c - 'a'];
        }
        return true;
        
    }
};
