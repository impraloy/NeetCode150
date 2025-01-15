/*
Test Case 1:
Input: height = [1,7,2,5,4,7,3,6]
Output: 36

Test Case 2:
Input: height = [2,2,2]
Output: 4
*/

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int results = 0;

        while(l<r){
            int area = (r-l) * min(heights[l], heights[r]);
            results = max(results, area);

            if(heights[l] <= heights[r]){
                l++;
            }else{
                r--;
            }
        }
        return results;
        
    }
};
