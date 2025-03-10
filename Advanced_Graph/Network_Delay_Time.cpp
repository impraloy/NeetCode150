class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> graph[n+1];
        for(auto time : times){
            graph[time[0]].push_back({time[1], time[2]});
        }
        vector<int> dis(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mheap;
        mheap.push({0,k});
        dis[k] = 0;

        while(!mheap.empty()){
            auto curr = mheap.top();
            mheap.pop();
            for(auto it : graph[curr.second]){
                if(dis[it.first] > dis[curr.second] + it.second){
                dis[it.first] = dis[curr.second] + it.second;
                mheap.push({dis[it.first], it.first});
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 1; i < n + 1; i++){
            if(dis[i] == INT_MAX) return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
        
    }
};
