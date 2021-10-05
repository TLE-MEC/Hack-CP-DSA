class Solution {
public:
    
    int dp[15][10001];
    
    int solve(vector<int>& arr,int m,int n)
    {
        if(n<0&&m==0)
            return -1;
        
        if(n<0)
          return 0;
            
        if(n==0)
            return 1;
        
        if(m==0)
            return 0;
        
//         if (m == 0 || n == 0)
//         {
           
             
//         }
         
        
        if(dp[m][n]!=-1)
           return dp[m][n];

        if(n-arr[m-1]<0)
            return dp[m][n]=solve(arr,m-1,n);
        
        else 
           return dp[m][n]=min(1+solve(arr,m,n-arr[m-1]),solve(arr,m-1,n));
        
    }
    
    int coinChange(vector<int>& coins, int amount) {
      
       
        memset(dp,-1,sizeof(dp));
        
        
         
        
       for(int i=0;i<=amount;i++)
          dp[0][i]=0;
        
       
        for(int i=0;i<15;i++)
           dp[i][0]=0;
        
        
        solve(coins,coins.size(),amount);
        
        if(dp[coins.size()][amount]==0)
            return -1;
        else
         return dp[coins.size()][amount];
        
    }
};