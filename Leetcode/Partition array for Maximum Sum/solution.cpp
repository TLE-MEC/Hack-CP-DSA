class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int K) {
        
        // We have to partition arrays into subarrays of length atmost l such that sum gets maximum
        int n = arr.size();
        vector<int> dp(n+1);
        
        for(int i=1; i<=n; i++)
        {
            // Current maximum till ith element and best sum till now
            int curmax = 0, best = 0;
            
            // With the help of dynamic programming we are check that at every i, if I add my current element
            // to the previous best sum till i-1, i-2, .... i-k, then maximum out of all these possible cases.
            for(int k=1; k<=K && i-k>=0; k++)
            {
                curmax = max(curmax, arr[i-k]);
                best = max(best, dp[i-k] + curmax * k);
            }
            dp[i] = best;
        }
        
        // return the best sum until nth element -  dp[n]
        return dp[n];
    }
};