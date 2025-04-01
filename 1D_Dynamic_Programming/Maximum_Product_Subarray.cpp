class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int results = nums[0];
        int cMax = 1, cMin = 1;

        for(auto num : nums){
            int tmp = cMax * num;
            cMax = max(max(num * cMax, num * cMin), num);
            cMin = min(min(num * cMin, tmp), num);
            results = max(results, cMax);
        }
        return results;      
    }
};
