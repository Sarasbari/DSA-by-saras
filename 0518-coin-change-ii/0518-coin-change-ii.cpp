class Solution {
public:
    int change(int amount, vector<int>& coins) {
        bool hastargetcoin = false;
        vector<int> othercoin;

        for (int coin : coins) {
            if (coin == amount)
                hastargetcoin = true;
            else
                othercoin.push_back(coin);
        }

        bool alleven = true;
        for (int coin : othercoin) {
            if (coin % 2 != 0) {
                alleven = false;
                break;
            }
        }

        if (hastargetcoin && amount % 2 != 0 && alleven)
            return 1;
        if (amount % 2 != 0 && alleven)
            return 0;

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int x = coin; x <= amount; x++) {
                dp[x] += dp[x - coin];
            }
        }

        return dp[amount];
    }
};