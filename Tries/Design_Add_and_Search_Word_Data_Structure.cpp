class TrieNode{
public:
    TrieNode* child[26];
    bool endOfWord;

    TrieNode(){
        for(auto &c : child){
            c = nullptr;
        }
        endOfWord = false;
    }

};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();  
    }
    
    void addWord(string word) {
        TrieNode* cur = root;

        for(auto &c : word){
            if(cur->child[c - 'a'] == nullptr){
                cur->child[c - 'a'] = new TrieNode();
            }
            cur = cur->child[c - 'a'];
        }
        cur->endOfWord = true;  
    }
    
    bool search(string word) {
        return dfs(0, word, root);
        
    }

private:
    bool dfs(int i, string word, TrieNode* root ){
        TrieNode* cur = root;
        for(;i < word.size(); i++){
            char c = word[i];
            if(c == '.'){
                for(TrieNode* child : cur->child){
                    if(child != nullptr && dfs(i+1, word, child)){
                        return true;
                    }
                }
                return false;
            }else{
                if(cur->child[c - 'a'] == nullptr){
                    return false;
                }
                cur = cur->child[c - 'a'];
            }
        }
         return cur->endOfWord;      

    }
};
