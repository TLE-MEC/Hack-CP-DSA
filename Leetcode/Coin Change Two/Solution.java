class Solution {
    public int change(int x, int[] coins) {
        // Create 1-D DP array to store the 
        // no. of combinations that can be made
        // for that amount
        int[] dp = new int[x+1];
        
        // base case eg: making 0 requires no coin
        // hence 1 combinations (pick nothing)
        dp[0] = 1;
        
        // the rest of the amounts are updated
        // by adding up all previous possible
        // combos that can add upto that amount
        
        // dp index-  0	|1	|2	|3	|4	|5	|
        // base case  1	|-	|-	|-	|-	|-	|
        // coins[0]:  1	|1	|1	|1	|1	|1	|
        // start here    *
        // coins[1]:  1	|1	|2	|2	|3	|3	|
        // start here        *
        // coins[2]:  1	|1	|2	|2	|3	|4	|
        // start here                    *
        
        for(int i = 0; i < coins.length; ++i) {
            for(int j = coins[i]; j <= x; ++j) {
                dp[j] += dp[j - coins[i]];
            }
            // _DEBUG
            // for(int j = 0; j <= x; j++) System.out.print(dp[j] + "\t|");
            // System.out.println();
        }
        
        return dp[x];
        
    }
}
