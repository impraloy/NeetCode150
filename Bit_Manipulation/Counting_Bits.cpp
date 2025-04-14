class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bin(n+1);
        int offset = 1;

        for(int i = 1; i <= n ; i++){
            if(offset * 2 == i){
                offset = i;
            }
            bin[i] = 1 + bin[i - offset];
        }
        return bin; 
    }
};
