/*
Test Case :
Input: nums = [1,2,1,0,4,2,6], k = 3
Output: [2,2,4,4,6]

Explanation: 
Window position            Max
---------------           -----
[1  2  1] 0  4  2  6        2
 1 [2  1  0] 4  2  6        2
 1  2 [1  0  4] 2  6        4
 1  2  1 [0  4  2] 6        4
 1  2  1  0 [4  2  6]       6

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> output(n-k+1);
        deque<int> q;
        int l = 0, r = 0;

        while(r < n){
            while(!q.empty() && nums[q.back()] < nums[r]){
                q.pop_back();
            }
            q.push_back(r);

            if(l > q.front()){
                q.pop_front();
            }

            if((r+1) >= k){
                output[l] = nums[q.front()];
                l++;
            }
            r++;
        }
        return output;
        
        
    }
};
