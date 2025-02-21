class Solution {
private:
    void fillIslands(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited){
        if(grid[i][j] == '0' || visited[i][j]) return;
        visited[i][j] = true;

        if(i + 1 < grid.size()){fillIslands(i + 1, j, grid, visited);}
        if(i - 1 >= 0){fillIslands(i - 1, j, grid, visited);}
        if(j + 1 < grid[0].size()){fillIslands(i, j + 1, grid, visited);}
        if(j - 1 >= 0){fillIslands(i, j - 1, grid, visited);}
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        int numOfIslands = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    numOfIslands++;
                    fillIslands(i, j, grid, visited);
                }
            }
        }
      return numOfIslands;
    }
};
