/*
Test Case 1:
Input: n = 1
Output: ["()"]

Test Case 2:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

class Solution {
public:
    void generateParenthesisHelper(int openN, int closeN, string s, vector<string>& res){
        if(openN == 0 && closeN == 0){ // when both openN and closeN are empty
            res.push_back(s);
            return;
        }

        if(openN > 0){ //when openN is not greater than 0
            string currentstr = s + '(';
            generateParenthesisHelper(openN - 1, closeN, currentstr, res);
        }

        if(openN < closeN){ //when closeN are reamremainingining
           string currentstr = s + ')';
           generateParenthesisHelper(openN, closeN - 1, currentstr, res); 
        }
    } 

    vector<string> generateParenthesis(int n) {
        vector<string> results;
        string str = "";
        generateParenthesisHelper(n, n, str, results);
        return results;  
    }

    
};
