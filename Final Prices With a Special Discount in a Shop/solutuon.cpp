class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();    // n contains vector size
        for( int i=0;i<n;i++){
             for( int j=i+1;j<n;j++){
                 if(prices[j] <= prices[i]){
                     prices[i]=prices[i]-prices[j];  // ith price updated ti difference of current ith-jth price
                     break;    // breaking out of loop
                 }
             }
           
        }
         return prices;   // returning the output
    }
};
