/* 
Test Case 1:
Input: s = "[]"
Output: true

Test Case 2:
Input: s = "([{}])"
Output: true

Test Case 3:
Input: s = "[(])"
Output: false

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(int i = 0; i< s.size(); i++){
            if(s[i] == '{' || s[i] == '[' || s[i] == '('){
                st.push(s[i]);
            }else{
                if(st.empty()) return false;

                if(st.top() == '{' && s[i] == '}' || st.top() == '[' && s[i] == ']' || st.top() == '(' && s[i] == ')'){
                    st.pop();
                }else
                return false;
            }
        }
        return st.empty() ? true : false;
    }
};
