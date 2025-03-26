class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        return dfs(s, 0, dp);
    }

private:
    int dfs(string s, int i, unordered_map<int, int>& dp) {
        if (dp.count(i)) {
            return dp[i];
        }
        if (s[i] == '0') {
            return 0;
        }

        int res = dfs(s, i + 1, dp);
        if (i + 1 < s.size() && (s[i] == '1' || 
            s[i] == '2' && s[i + 1] < '7')) {
            res += dfs(s, i + 2, dp);
        }
        dp[i] = res;
        return res;
    }
};