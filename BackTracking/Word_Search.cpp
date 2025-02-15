class Solution {
private:
   bool dfs(int pos, int i, int j, string &word, vector<vector<char>> &board){
    char c = board[i][j];
    if(c == '#') return false;
    if(pos >= word.size() || c != word[pos]) return false;
    if(pos == word.size()-1 && c == word[pos]) return true;

    pos++;
 
    board[i][j] = '#';
    
    if(i + 1 < board.size() && dfs(pos, i + 1, j, word, board)) return true;
    if(i - 1 >= 0 && dfs(pos, i - 1, j, word, board)) return true;
    if(j + 1 < board[0].size() && dfs(pos, i, j + 1, word, board)) return true;
    if(j - 1 >= 0 && dfs(pos, i, j - 1, word, board)) return true;
    board[i][j] = c;
    return false;
   }

public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(dfs(0, i, j, word, board)){
                    return true;
                    }
            }
        }
        return false;
    }
};
