class Solution {
private:
    int findArea(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited){
        if(!grid[i][j] || visited[i][j]) return 0;
        visited[i][j] = true;
        int area = 1;

        if(i + 1 < grid.size()){area += findArea(i + 1, j, grid, visited);}
        if(i - 1 >= 0){area += findArea(i - 1, j, grid, visited);}
        if(j + 1 < grid[0].size()){area += findArea(i, j + 1, grid, visited);}
        if(j - 1 >= 0){area += findArea(i, j - 1, grid, visited);}

        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                int area = findArea(i, j, grid, visited);
                maxArea = max(maxArea, area);
            }
        }
        return maxArea;
    }
};
