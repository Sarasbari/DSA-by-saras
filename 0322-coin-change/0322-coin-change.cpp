class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = 1e9;
        }

        for (int i = 1; i < n; i++) {
            for (int target = 0; target <= amount; target++) {
                int notTaken = prev[target];
                int take = 1e9;
                if (coins[i] <= target) {
                    take = 1 + curr[target - coins[i]];
                }
                curr[target] = min(notTaken, take);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};