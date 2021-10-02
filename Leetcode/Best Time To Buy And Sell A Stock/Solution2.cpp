//Profit = Selling price - purchase price
//With each loop, we compare prices[i] element with the previous minimum value and update accordingly
//With each loop, we compute profit , if the value of profit is greater than the previous value, update profit to get max profit.


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int min_value=prices[0];
        for(int i=1;i<prices.size();i++){
           min_value=min(prices[i],min_value);
            profit=max(profit,(prices[i]-min_value);//max profit
        }
        return profit;
    }
};
