class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        for(int idx = cost.size() - 1; idx >= 0; idx-- ){
            cost[idx] += min(cost[idx+1], cost[idx+2]);
        }
        return min(cost[0], cost[1]);
        
    }
};
