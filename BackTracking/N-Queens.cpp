class Solution {
private:
   void backtrack(int i, vector<vector<string>> &result, vector<string> &board, unordered_set<int> &cols,
        unordered_set<int> &diag45, unordered_set<int> &diag135){
            if(i == board.size()){
                result.push_back(board);
                return;
            }

            for(int j = 0; j < board[0].size(); j++){
                if(cols.count(j) || diag45.count(i+j) || diag135.count(i-j)){
                    continue;
                }

                cols.insert(j);
                diag45.insert(i+j);
                diag135.insert(i-j);
                board[i][j] = 'Q';
                backtrack(i + 1, result, board, cols, diag45, diag135);

                cols.erase(j);
                diag45.erase(i+j);
                diag135.erase(i-j);
                board[i][j] = '.';
            }
        }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> cols;
        unordered_set<int> diag45;
        unordered_set<int> diag135;
        int i = 0;

        backtrack(i, result, board, cols, diag45, diag135);
        return result;  
    }
};
