class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;

        unordered_map<int, int> setS;
        unordered_map<int, int> setT;
        for(int i =0; i<s.length(); i++){
            setS[s[i]]++;
            setT[t[i]]++;
        }
        return setS == setT;
        
    }
};
