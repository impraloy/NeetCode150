/*
Test Case : 1
Input: s = "XYYX", k = 2
Output: 4

Test case 2:
Input: s = "AAABABB", k = 1
Output: 5
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int results = 0;
        int l = 0, maxFrequency = 0, n = s.size();

        for(int r = 0; r<n; r++){
            count[s[r]]++;
            maxFrequency = max(maxFrequency, count[s[r]]);

            while((r-l+1) - maxFrequency > k){
                count[s[l]]--;
                l++;
            }
            results = max(results, r-l+1);
        }
        return results;
        
    }
};
