class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int m = 1; m <= amount; m++) {
            for (int n = 0; n < coins.size(); n++) {
                if (coins[n] <= m) {
                    dp[m] = min(dp[m], dp[m - coins[n]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};