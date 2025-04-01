#include <bits/stdc++.h>

using namespace std;

// TC O(n)
// int maxProfit(vector<int> &prices)
// {
//     int profit = 0;
//     int buy = prices[0];
//     for (int i = 0; i < prices.size(); i++)
//     {
//         buy = min(buy, prices[i]);
//         profit = max(profit, prices[i] - buy);
//     }
//     return profit;
// }

int maxProfit(vector<int> &prices)
{
    int buy = prices[0], sell = 0;
    int profit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < buy)
        {
            buy = prices[i];
            sell = prices[i];
        }
        else if (sell < prices[i])
        {
            sell = prices[i];
            profit = max(profit, sell - buy);
        }
    }
    return profit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(prices);
    cout << result << endl;
    return 0;
}