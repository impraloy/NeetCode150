/*
test case 
Input: numbers = [1,2,3,4], target = 7
Output: [1,2]
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int l = 0, r = numbers.size()-1;

        while(l < r){
            int currentSum = numbers[l] + numbers[r];
            if(currentSum > target){
                r--;
            }else if(currentSum <target){
                l++;
            }else{
                return {l+1, r+1};
            }
        }
        return {};
        
    }
};
