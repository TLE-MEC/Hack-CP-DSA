class Solution {
    // We have to find distinct ways to reach top by taking 1-2 steps.
    public int climbStairs(int n) {
    //    To access Nth index we have to make DP of N+1 size.
        int[] dp = new int[n+1];
        dp[0] = 1; //   Numbers of ways from position X to X is 1.
        
        // Number of ways to reach Ith stairs is sum of ways to reach i-1 and i-2 level.
        for(int i=1;i<dp.length;i++){
            dp[i] = dp[i-1];
            if(i-2>=0) dp[i]+=dp[i-2];
        }
        
        // ans must be recieved at last index.
        return dp[dp.length-1];
    }
}