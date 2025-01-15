/*
Test Case 1 : 
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Test Case 2:
Input: nums = [0,1,1]
Output: []

Test Case 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int l = i+1, r = nums.size()-1;

            while(l<r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0){
                    r--;
                }else if(sum < 0){
                    l++;
                }else{
                    results.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1]){
                        l++;
                    }
                }
            }
        }
        return results;
        
    }
};
