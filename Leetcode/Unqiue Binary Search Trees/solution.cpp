/*
We use a dynamic programming approach:
Say for n=3, we have 3 choices for the root node, leaving us with the following subproblems to solve:
    1                 2                  3
  /   \              /  \              /   \
{}   {2,3}        {1}    {3}         {1,2}  {}

The recurrence relation becomes:
    dp[3] = dp[0]*dp[2] + dp[1]*dp[1] + dp[2]*dp[0]

In general:
    dp[n] = dp[0]*dp[n-1] + dp[1]*dp[n-2] + dp[2]*dp[n-2] ... + dp[n-1]*dp[0]
*/
class Solution {
public:
    int numTrees(int n)
    {
        int dp[n+1]; 
        dp[0] = 1; //Only 1 way to make a tree with 0 nodes
        dp[1] = 1; //Only 1 way to make a tree with 1 node
        for( int i=2 ; i<=n ; i++ )
        {
            dp[i] = 0;
            for( int j=0 ; j<i ; j++ )
            {
                dp[i] += dp[j]*dp[i-1-j];
            }
        }
        
        return dp[n];
    }
};