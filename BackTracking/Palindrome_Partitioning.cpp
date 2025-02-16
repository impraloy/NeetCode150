class Solution {
private:
    bool isPalindrome(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void partition(int i, string &s, vector<string> &par, vector<vector<string>> &result){
        if( i == s.length()){
            result.push_back(par);
            return;
        }

        for(int j = i; j < s.length(); j++){
            if(isPalindrome(s, i, j)){
                par.push_back(s.substr(i, j - i + 1));
                partition(j + 1, s, par, result);
                par.pop_back();
            }
        }
    }


public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> par;
        int i = 0;
        partition(i, s, par, result);
        return result;    
    }
};
