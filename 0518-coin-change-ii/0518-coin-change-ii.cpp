class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);

        for (int i = 0; i <= amount; i++) {
            if (i % coins[0] == 0)
                prev[i] = 1;
        }

        for (int i = 1; i < n; i++) {
            vector<int> curr(amount + 1, 0);
            for (int target = 0; target <= amount; target++) {
                long notTaken = prev[target];
                long taken = 0;
                if (coins[i] <= target)
                    taken = curr[target - coins[i]];
                curr[target] = notTaken + taken;
            }
            prev = curr;
        }
        return prev[amount];
    }
};