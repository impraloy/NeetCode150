class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> que;
        int time = 0;
        int freshOrg = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    freshOrg++;
                }
                if(grid[i][j] == 2){
                    que.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(freshOrg > 0 && !que.empty()){
            int n = que.size(); // Store the initial size of the queue
            for(int q = 0; q < n; q++){
                int r = que.front().first;
                int c = que.front().second;
                que.pop();

                for(const auto& d : dir){
                    int row = r + d.first;
                    int col = c + d.second;

                    if(row >= 0 && row < grid.size() &&
                       col >= 0 && col < grid[0].size() &&
                       grid[row][col] == 1){
                       grid[row][col] = 2;
                       que.push({row, col});
                       freshOrg--;
                    }
                }
            }
            time++;
        }
        return freshOrg == 0 ? time : -1;
    }
};
