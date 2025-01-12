class Solution {
public:

    string encode(vector<string>& strs) {
        string encodedString;
        for(const string& s : strs){
            encodedString+= to_string(s.size())+ "#" +s;
        }
        return encodedString;

    }

    vector<string> decode(string s) {
        vector<string> decodedString;
        int i = 0;
        while(i <s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i, j-i));
            i = j+1;
            j = i + length;
            decodedString.push_back(s.substr(i, length));
            i = j;

        }
        return decodedString;

    }
};
