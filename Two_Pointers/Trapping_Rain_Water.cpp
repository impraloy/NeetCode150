/*
Test Case:
Input: height = [0,2,0,3,1,0,1,3,2,1]
Output: 9
*/

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()){
            return 0;
        }

        int l = 0, r = height.size()-1;
        int leftMax = height[l], rightMax = height[r];
        int results = 0;

        while(l < r){
            if(leftMax < rightMax){
                l++;
                leftMax = max(leftMax, height[l]);
                results += leftMax - height[l];
            }else{
                r--;
                rightMax = max(rightMax, height[r]);
                results += rightMax - height[r];
            }
        }
        return results;


        
    }
};
