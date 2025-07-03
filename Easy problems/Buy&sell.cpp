// 121. **Best Time to Buy and Sell Stock** (platform: LeetCode,geeksforgeeks) (array)

/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing
 a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.*/

// These code applies only for single transaction.
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int maxprice = 0;
    int minprice = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        minprice = min(minprice, prices[i]);
        maxprice = max(maxprice, prices[i] - minprice);
    }
    return maxprice;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int result = maxProfit(prices);
    cout << "Maximum profit: " << result << endl;

    return 0;
}

// Time complexity: O(n)
// Space complexity: O(1)

// for multiple transactions, you can use the following code:
int maxProfitMultipleTransactions(vector<int> &arr)
{
    int profit = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] > arr[i - 1])
        {
            profit += arr[i] - arr[i - 1];
        }
    }
    return profit;
}

// Time complexity: O(n)
// Space complexity: O(1)