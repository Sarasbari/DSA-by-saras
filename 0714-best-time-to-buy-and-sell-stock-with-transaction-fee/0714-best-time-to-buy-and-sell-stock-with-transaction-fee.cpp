class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0)
            return 0;

        vector<long> curr(2, 0);
        vector<long> ahead(2, 0);
        ahead[0] = ahead[1] = 0;
        long profit;

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 0)
                    profit = max(0 + ahead[0], -prices[i] + ahead[1]);
                if (buy == 1)
                    profit = max(0 + ahead[1], prices[i] - fee + ahead[0]);
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return curr[0];
    }
};