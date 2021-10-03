//Easiest 1 pass O(1) solution

int maxProfit(vector<int>& prices) {
        int maxPro = 0;  //Variable to store the maximum profit
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i] < prices[i+1]){
                maxPro += prices[i+1] - prices[i];  //Keep on adding profits to maxPro
            }
        }
        return maxPro;
    }
