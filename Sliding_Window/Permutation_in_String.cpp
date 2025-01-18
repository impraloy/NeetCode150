/* Test Case: 1
Input: s1 = "abc", s2 = "lecabee"
Output: true

Test Case 2:
Input: s1 = "abc", s2 = "lecaabee"
Output: false
*/
class Solution {
public:

    bool isFrequency(int freq1[], int freq2[]){
        for(int i = 0; i<26; i++){
            if (freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    
    bool checkInclusion(string s1, string s2) {
        int Freq[26] = {0};
        for(int i = 0; i<s1.length(); i++){
            Freq[s1[i] - 'a']++;
        }

        int windowSize = s1.length();

        for(int i = 0; i<s2.length(); i++){
            int windowIdx = 0, idx = i;
            int windowFreq[26] = {0};

            while(windowIdx < windowSize && idx < s2.length()){
                windowFreq[s2[idx] - 'a']++;
                windowIdx++;
                idx++;
            }

            if(isFrequency(Freq, windowFreq)){
                return true;
            }
        }
         return false;

    }
};
