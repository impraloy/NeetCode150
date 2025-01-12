class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> list;
      for(string s : strs){
        string key = s;
        sort(key.begin(), key.end());
        list[key].push_back(s);
      }

      vector<vector<string>> results;
      for(auto& pair: list){
        results.push_back(pair.second);
      }
      return results;
    }
};
