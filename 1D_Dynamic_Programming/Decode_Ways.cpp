class Solution {
public:
    int numDecodings(string s) {
        int dRes = 0, d1 = 1, d2 = 0;
        int n = s.size();
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0'){
                dRes = 0;
            }
            else{
                dRes = d1;
                if(i + 1 < n && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7')){
                    dRes += d2;
                }
            }
            d2 = d1;
            d1 = dRes;
            dRes = 0;
        }
        return d1;

        
    }
};
