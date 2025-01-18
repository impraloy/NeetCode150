/*
Test Case 1:
Input: temperatures = [30,38,30,36,35,40,28]
Output: [1,4,1,2,1,0,0]

Test Case 2:
Input: temperatures = [22,21,20]
Output: [0,0,0]
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        vector<int> results(temperatures.size(), 0);
        stack<pair<int, int>> stk;  

        for(int i = 0; i<temperatures.size(); i++){
            while(!stk.empty() && temperatures[i] > stk.top().first){
                auto pair = stk.top();
                stk.pop();
                results[pair.second] = i - pair.second;
            }
            stk.push({temperatures[i], i});
        }
        return results;
        
    }
};
