//


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int min_value=prices[0];
        for(int i=1;i<prices.size();i++){
           min_value=min(prices[i],min_value);
            profit=max(profit,(prices[i]-min_value);
        }
        return profit;
    }
};
