class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int num : nums){
            map[num]++;
        }

        priority_queue<pair<int, int>>queue;

        for(auto it : map){
            queue.push({it.second, it.first});
        }

        vector<int>results;
        while(k--){
            int val = queue.top().second;
            queue.pop();
            results.push_back(val);
        }
        return results;
    }
};
