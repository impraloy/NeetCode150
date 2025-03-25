class Solution {
public:
    int countSubstrings(string s) {
        int result = 0;
        int n = s.size();

        for(int i = 0; i < n; i++){
            //odd case
            int l = i, r = i;
            while(l >= 0 && r < n && s[l] == s[r]){
                result++;
                l--;
                r++;
            }

            //even case
             l = i;
             r = i + 1;
             while(l >= 0 && r < n && s[l] == s[r]){
                result++;
                l--;
                r++;
            }
        }
        return result;
        
    }
};
