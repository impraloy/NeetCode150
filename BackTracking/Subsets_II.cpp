class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        vector<int> curr;
        solveSubsetsWithDup(nums, curr, i);
        return results;
    }
private:
    void solveSubsetsWithDup(vector<int>& nums, vector<int> &curr, int i ){
        if(i == nums.size()){
            results.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solveSubsetsWithDup(nums, curr, i + 1);
        curr.pop_back();

        while(i + 1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }
        solveSubsetsWithDup(nums, curr, i + 1);
    }
};
