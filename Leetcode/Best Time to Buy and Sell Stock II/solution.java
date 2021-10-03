class Solution {
    public int maxProfit(int[] prices) {
        
        // Initialize the profit value
        int profit = 0;

        // Loop through for the 'length-of-array' times
        for(int i=1; i < prices.length; i++){
          
            // If the difference in values is positive, add them to profit
            if((prices[i] - prices[i-1]) > 0)
                profit += (prices[i] - prices[i-1]) ;
        }

        // Return profit
        return profit;
    }
}
