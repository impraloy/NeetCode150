/*
Test Case 1:
Input: s = "OUZODYXAZV", t = "XYZ"
Output: "YXAZ"

Test Case 2:
Input: s = "xyz", t = "xyz"
Output: "xyz"

Test Case 3:
Input: s = "x", t = "xy"
Output: ""

*/
class Solution {
public:
    string minWindow(string s, string t) {
        //when t string is empty
        if(t.empty()){
            return "";
        }

        //create two map countT and window
        unordered_map<char, int> countT, window;
        for(char c : t){ //iterate throw t and store char in map countT
            countT[c]++;
        }

        int have = 0, need = countT.size();
        pair<int, int> results = {-1, -1};
        int resultsLen = INT_MAX;
        int l = 0;

        for(int r = 0; r<s.length(); r++){
            char c = s[r];
            window[c]++; //storing all char in window map

            //when char at window and countT are equal then increase the have
            if (countT.count(c) && window[c] == countT[c]){
                have++;
            }

            while(have == need){
                //If current slide window length is smaller than resultslen
                //current slide window len will be new results len
                //reults will be current slide window
                if((r-l+1) < resultsLen){
                    resultsLen = r-l+1;
                    results = {l, r};
                }

                //else decrease the slide window from the left side
                window[s[l]]--;
                 
                //If count left window char match to countT map and
                //window char count is less than countT char count
                //than decrease the have
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    have--;
                }
                //else move left to right
                l++;
            }
        }
        
        return resultsLen == INT_MAX ? "" : s.substr(results.first, resultsLen);
        
    }
};
