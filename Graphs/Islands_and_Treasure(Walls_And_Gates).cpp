class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0){
                    que.push({i, j});
                }
            }
        }

        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while(!que.empty()){
            int row = que.front().first;
            int col = que.front().second;
            que.pop();

            for(int d = 0; d < 4; d++){
                int r = row + dir[d][0];
                int c = col + dir[d][1];

                if(r < 0 || r >= grid.size() || 
                   c < 0 || c >= grid[0].size() ||
                   grid[r][c] != INT_MAX) continue;

                grid[r][c] = grid[row][col] + 1;
                que.push({r, c});
            }
        }
        
    }
};
