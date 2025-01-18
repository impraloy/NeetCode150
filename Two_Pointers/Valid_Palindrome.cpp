class Solution {
public:
    bool isPalindrome(string s) {
        int l= 0, r= s.length()-1;
        while(l<r){
            while(l<r && !ValidAlphaNum(s[l])){
                l++;
            }
            while(r>l && !ValidAlphaNum(s[r])){
                r--;
            }
            while(tolower(s[l]) != tolower(s[r])){
                return false;
            }
            l++;
            r--;
            

        }
        return true;
        
    }

    bool ValidAlphaNum(char c){
        return (c>= 'A' && c<= 'Z' ||
                c>= 'a' && c<= 'z' ||
                c>= '0' && c<= '9');
    }
};
