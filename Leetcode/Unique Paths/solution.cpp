class Solution {
public:
    int uniquePaths(int m, int n) {
        
        // this is a dynammic programming problem - count the number of unique path
        int dp[m][n]; // represent the m * n grid
        memset(dp, 0, sizeof(dp));   // 2-d array initialised to zero
        
        // The initial subgrid [0][0] have in total one possible unique path
        dp[0][0] = 1;
        
        // For every element in first row and first column, there is only a single path to reach them
        
        for(int i=0; i<m; i++)
            dp[i][0] = 1;
        
        for(int i=0; i<n; i++)
            dp[0][i] = 1;
        
        // For every other position in grid, the total number of unique ways: 
        // it is the sum of number of unique paths on left of it and number of unique paths till top of that element
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        
        // Answer will be the ways to reach till position m - 1, n - 1 as array is zero indexed
        return dp[m-1][n-1];
    }
};