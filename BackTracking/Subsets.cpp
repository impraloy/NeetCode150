class Solution {
private:
    void callSubsets(const vector<int>& nums, int i, vector<vector<int>> &results,vector<int> &subset){
        if(i>= nums.size()){
            results.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        callSubsets(nums, i+1, results, subset);
        subset.pop_back();
        callSubsets(nums, i+1, results, subset);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> subset;
        int i = 0;
        callSubsets(nums, i, results, subset);
        return results;      
    }
};
