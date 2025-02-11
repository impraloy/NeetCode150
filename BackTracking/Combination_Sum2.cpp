class Solution {
public:
    vector<vector<int>> results;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
     sort(candidates.begin(), candidates.end());
     vector<int> curr;
     int i = 0, total = 0;
     callCombinationSum2(candidates, target, curr, total, i);
     return results;   
    }

private:
     void callCombinationSum2(vector<int>& candidates, int target,  vector<int> &curr, int total, int i ){
        if(total == target){
            results.push_back(curr);
            return;
        }

        if(total > target || i == candidates.size()){
          return;
        }

        curr.push_back(candidates[i]);
        callCombinationSum2(candidates, target, curr, total + candidates[i], i + 1);
        curr.pop_back();

        while(i + 1 < candidates.size() && candidates[i] == candidates[i+1]){
            i++;
        }
        callCombinationSum2(candidates, target, curr, total, i + 1);
     }
};
