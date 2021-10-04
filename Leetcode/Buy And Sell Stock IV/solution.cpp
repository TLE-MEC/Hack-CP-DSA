class Solution {
public:
    int solve(vector<int>&prices, bool isBuy,int k,int curr,int k2,map<string,int>&m)
    {
        if(curr==prices.size() || k==k2)
            return 0;
        string key = to_string(curr) + "-" + to_string(isBuy) + "-" + to_string(k);   // our memo. memo will hold the max profit for a currentIndex/bought or not bought/transaction number
       if( m.find(key)!=m.end())
           return m[key];
        int x1,x2;
            if(!isBuy)   // if we haven't bought anything, we can buy stocks today. so we have 2 choices. buy or dont buy
            {
                x1 = solve(prices,!isBuy,k,curr+1,k2,m)-prices[curr];
                x2 = solve(prices,isBuy,k,curr+1,k2,m);
            }
            else  // else we have 2 choices. sell today or dont sell
            {
                x1 = solve(prices,!isBuy,k+1,curr+1,k2,m)+prices[curr];
                x2 = solve(prices,isBuy,k,curr+1,k2,m);
            }
        
        return m[key]= max(x1,x2);  // the best solution will be the maximum of 2 cases
    }
    int maxProfit(int k, vector<int>& prices) {
        bool isBuy=false;  // nothing is bought currently
        map<string,int>m;   
        return solve(prices,isBuy,0,0,k,m);
    }
};
