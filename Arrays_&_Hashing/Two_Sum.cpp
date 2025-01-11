class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> hash_map;

        for(int i = 0; i < nums.size(); i++){
            hash_map[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
            int complement = target -nums[i];
            if(hash_map.count(complement) && hash_map[complement] != i ){
                return {i, hash_map[complement]};
            }
        }
        return {};


    }
};
