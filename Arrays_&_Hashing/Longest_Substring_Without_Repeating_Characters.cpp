/*
Test case 1:
Input: s = "zxyzxyz"
Output: 3

Test Case 2:
Input: s = "xxxx"
Output: 1
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;

        int l = 0, results = 0, n = s.size();
        for(int r = 0; r<n; r++){
            if(map.find(s[r]) != map.end()){
                l = max(l, map[s[r]]+1);
            }
            map[s[r]] = r;
            results = max(results, r-l +1);
        }
        return results;
        
    }
};
