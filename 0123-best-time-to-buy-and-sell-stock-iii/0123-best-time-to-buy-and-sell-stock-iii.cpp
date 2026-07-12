class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> ahead(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int i = prices.size() - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= 2; cap++) {
                    if (buy == 0)
                        curr[buy][cap] =
                            max(0 + ahead[0][cap], -prices[i] + ahead[1][cap]);
                    if (buy == 1)
                        curr[buy][cap] =
                            max(0 + ahead[1][cap], prices[i] + ahead[0][cap-1]);
                }
            }
            ahead = curr;
        }
        return ahead[0][2];
    }
};