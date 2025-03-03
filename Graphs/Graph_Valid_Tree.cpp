class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int node = 0, prevNode = -1;
        if(edges.size() > n - 1) return false;

        vector<vector<int>> adj(n);
        for(const auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;

        if(!findValidTree(node, prevNode, visited, adj)) return false;

        return visited.size() == n;
    }

private:
    bool findValidTree(int node, int prevNode, unordered_set<int> &visited,
    vector<vector<int>> &adj){
        
        if(visited.count(node)) return false;

        visited.insert(node);

        for(auto nei : adj[node]){
            if(nei == prevNode) continue;

            if(!findValidTree(nei, node, visited, adj)) return false;
        }
        return true;
    }
};
