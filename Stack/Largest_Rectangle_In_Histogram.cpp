/*
Test Case 1:
Input: heights = [7,1,7,2,2,4]
Output: 8

Test Case 2:
Input: heights = [1,3,7]
Output: 7
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> stk;
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++){
            int left = i;
            while(!stk.empty() && stk.top().second > heights[i]){
                pair<int, int> top = stk.top();
                stk.pop();
                maxArea = max(maxArea, top.second * (i-top.first));
                left = top.first;
            }
            stk.push({left, heights[i]});
        }

        while(!stk.empty()){
            pair<int, int> top = stk.top();
            stk.pop();
            int width = heights.size() - top.first;
            maxArea = max(maxArea, top.second * width);
        }
        return maxArea;
        
    }
};
