/*
Test Case 1:
Input: nums = [-1,0,2,4,6,8], target = 4
Output: 3

Test Case 2:
Input: nums = [-1,0,2,4,6,8], target = 3
Output: -1
*/

class Solution {
public:

    int binary_search(int low, int high, vector<int>& nums, int target){
        if(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[mid] == target) return mid;

            return ((nums[mid] > target) ? binary_search(low, mid - 1, nums, target) : binary_search(mid + 1, high, nums, target));
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        return binary_search(low, high, nums, target);

        
    }
};
