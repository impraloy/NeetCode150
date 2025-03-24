class Solution {
public:
    string longestPalindrome(string s) {

        int resLen = 0, resIdx = 0;
        
        //odd
        for(int i = 0; i <s.size(); i++){
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > resLen){
                    resIdx = l;
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        
        //even
           l = i;
           r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > resLen){
                    resIdx = l;
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        return s.substr(resIdx, resLen);
        
    }
};
