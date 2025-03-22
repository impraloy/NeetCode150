class Solution {
public:
    int rob(vector<int>& nums) {
        int results;
        vector<int> num1(nums.begin() + 1, nums.end());
        vector<int> num2(nums.begin(), nums.end() - 1);
        results = max(nums[0], max(dfs(num1), dfs(num2)));
        return results;
    }


private:
        int dfs(vector<int>& nums){
            int house1 = 0, house2 = 0;
            for(int n : nums){
                int temp = max(house1 + n, house2);
                house1 = house2;
                house2 = temp;
            }
            return house2; 
        }
};
