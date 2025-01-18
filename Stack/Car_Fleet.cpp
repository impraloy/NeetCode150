/* 
Test Case 1:
Input: target = 10, position = [1,4], speed = [3,2]
Output: 1

Test Case 2:
Input: target = 10, position = [4,1,0,7], speed = [2,2,1,1]
Output: 3
*/

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pair;

        for(int i = 0; i<position.size(); i++){
            pair.push_back({position[i], speed[i]});
        }

        sort(pair.rbegin(), pair.rend());
        vector<double> stk;

        for(auto& p : pair){
            stk.push_back((double)(target - p.first) / p.second);

            if(stk.size() >= 2 && stk.back() <= stk[stk.size()-2]){
                stk.pop_back();
            }
        }
        return stk.size();
    }
};
