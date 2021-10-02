/*
You want to maximize your profit by choosing a single day to buy 
one stock and choosing a different day in the future to sell that stock.

Approach:-

minPrice -> minimum price of the stock till ith day

So, profit at ith day = prices[i] - minPrice

This way we can calculate the max profit.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxProfit = 0;      // initially is zero
        int minPrice = INT_MAX; // intially is INT_MAX

        for (auto price : prices)
        {
            minPrice = min(minPrice, price);              // update the minPrice
            maxProfit = max(maxProfit, price - minPrice); // update the maxProfilt -> (profit at ith day = price - minPrice)
        }

        return maxProfit;
    }
};
