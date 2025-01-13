class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> results (nums.size(), 1);
        for(int i=1; i<nums.size(); i++){
            results[i] = results[i-1] * nums[i-1];
        }

        int prefix = 1;
        for(int i=nums.size()-1; i>=0; i--){
            results[i] = results[i] * prefix;
            prefix = prefix * nums[i];
        }

        return results;

    }
};
