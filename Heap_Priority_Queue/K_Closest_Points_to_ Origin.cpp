class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comparison = [](const vector<int>& a, const vector<int>& b){
            return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(comparison)> minheap(comparison);

        for(const auto& point : points){
            minheap.push({point[0], point[1]});
        }
        vector<vector<int>> res;

    while(k> 0){
        res.push_back(minheap.top());
        minheap.pop();
        k--;
    }
    return res;
        


        
    }
};
