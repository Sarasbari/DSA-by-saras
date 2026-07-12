class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MIN;
        int sell1 = 0;
        int buy2 = INT_MIN;
        int sell2 = 0;

        for (int price : prices) {
            buy1 = max(-price, buy1);
            sell1 = max(sell1, buy1 + price);
            buy2 = max(sell1 - price, buy2);
            sell2 = max(sell2, buy2 + price);
        }
        return sell2;
    }
};