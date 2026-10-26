class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 1e8);
        dp[0] = 0;

        for (int c : coins) {
            for (int t = c; t <= amount; t++) {
                dp[t] = min(dp[t], 1 + dp[t - c]);
            }
        }
        return dp[amount] == 1e8 ? -1 : dp[amount];
    }
};