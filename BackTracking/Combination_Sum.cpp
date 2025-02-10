class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        int i = 0;

        fillCombination(nums, target, curr, i);
        return results;
    }

private:
    void fillCombination(vector<int>& nums, int target, vector<int>& curr, int i){
        if(target == 0){
            results.push_back(curr);
            return;
        }
        if(target < 0 || i >= nums.size()){
            return;
        }

        curr.push_back(nums[i]);
        fillCombination(nums, target - nums[i], curr, i);
        curr.pop_back();
        fillCombination(nums, target, curr, i+1);
    }
};
