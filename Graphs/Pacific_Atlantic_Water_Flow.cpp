class Solution {
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<int>> result;

        for(int j = 0; j < heights[0].size(); j++){
            ocean(0, j, pacific, heights);
            ocean(heights.size()-1, j, atlantic, heights);

        }

        for(int i = 0; i < heights.size(); i++){
            ocean(i, 0, pacific, heights);
            ocean(i, heights[0].size()-1, atlantic, heights);

        }

        for(int r = 0; r < heights.size(); r++){
            for(int c = 0; c < heights[0].size(); c++){
                if(pacific[r][c] && atlantic[r][c]){
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }

private:
    void ocean(int i, int j, vector<vector<bool>> &oceanVisited, vector<vector<int>> &heights){
        oceanVisited[i][j] = true;

        for(auto [di, dj] : dir){
            int r = i + di;
            int c = j + dj;

            if( r >= 0 && r < heights.size() && c >= 0 && c < heights[0].size()
               && !oceanVisited[r][c] && heights[r][c] >= heights[i][j]){
                ocean(r, c, oceanVisited, heights);
               }
        }
    }
};
