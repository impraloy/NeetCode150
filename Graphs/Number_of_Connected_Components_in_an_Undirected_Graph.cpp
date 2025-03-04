class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        int result = 0;

        for(const auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(adj, visited, i);
                result++;
            }
        }
        return result;
    }

private: 
    void dfs(vector<vector<int>> &adj,  vector<bool> &visited, int i){
        visited[i] = true;

        for(auto nb : adj[i]){
            if(!visited[nb]){
                dfs(adj, visited, nb);
            }
        }
    }
};
