/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Example
Input : [1 2 1 2]
Output : 2

Explanation:
  Day 1 : Buy
  Day 2 : Sell
  Day 3 : Buy
  Day 4 : Sell
Hint 1
Think DP.

What are the essential things you need to keep in your DP states?

You will need to store maximum number of transactions you can do in any suffix/prefix of array.

Solution Approach
What if you construct your DP space as :

f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions

How would you fill in values in f[k, ii] and how would the DP relations look like.
*/

#include "bits/stdc++.h"
using namespace std;

int solve(vector<int> &prices, int k)
{
   int n = prices.size();
   if (k >= n / 2)
   {
      int profit = 0;
      for (int i = 1; i < n; i++)
         if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
      return profit;
   }

   vector<int> buy(k + 1, INT_MIN);
   vector<int> sell(k + 1, 0);

   int ans = 0;
   for (int i = 0; i < n; i++)
   {
      for (int j = 1; j <= k; j++)
      {
         buy[j] = max(buy[j], sell[j - 1] - prices[i]);
         sell[j] = max(sell[j], buy[j] + prices[i]);
      }
   }

   return sell[k];
}
