class Solution {
private:
    void backtracking(int i, string curStr, string &digits, vector<string> &result, unordered_map<char, string> &map){
        if(curStr.length() == digits.length()){
            result.push_back(curStr);
            return;
        }
        string options = map[digits[i]];
        for(auto &c : options){
            curStr.push_back(c);
            backtracking(i+1, curStr, digits, result, map);
            curStr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string curStr = "";
        int i = 0;
        if(digits.empty()) return result;
        unordered_map<char, string> map;
        map['2'] = "abc";
        map['3'] = "def";
        map['4'] = "ghi";
        map['5'] = "jkl";
        map['6'] = "mno";
        map['7'] = "pqrs";
        map['8'] = "tuv";
        map['9'] = "wyxz";
        backtracking(i, curStr, digits, result, map);
        return result; 
    }
};
