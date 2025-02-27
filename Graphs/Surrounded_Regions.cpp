class Solution {
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, 
                                         {0, 1}, {0, -1}};
public:
    void solve(vector<vector<char>>& board) {

        dfs(board);
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }else if (board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
        
    }

private:
    void dfs(vector<vector<char>> &board){
        queue<pair<int, int>> que;

       for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(i == 0 || i == board.size()-1 ||
                   j == 0 || j == board[0].size()-1 &&
                   board[i][j] == 'O'){
                    que.push({i, j});
               }
            }
        }

        while(!que.empty()){
            auto [i, j] = que.front();
            que.pop();

            if(board[i][j] == 'O'){
                board[i][j] = 'T';
                for(auto &d : dir){
                    int r = i + d.first;
                    int c = j + d.second;

                    if(r >= 0 && r < board.size() &&
                       c >= 0 && c < board[0].size()){
                        que.push({r, c});
                       }
                }
            }
        }

    }
};
