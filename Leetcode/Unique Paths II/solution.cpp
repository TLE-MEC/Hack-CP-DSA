/*
It is a advanced version of Unique Paths, so first check it out in the repo.
In this version we have the added issue of obstacles.
We have to modify the base conditions and recurrence relation to account for obstacles
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        vector<vector<int>>& obs = obstacleGrid; //refernce to input for easier typing
        if( obs[0][0] == 1 ) //if starting point has obstacle, there are no possible paths
            return 0;
        vector<vector<int>> dp( obs.size() , vector<int>( obs[0].size(), 0 )); //DP grid with same size as obstacle grid, initialised to 0
        
        //For squares along the starting edges, each square has 1 unique path until we encounter an obstacle
        for( int i=0 ; i<dp.size() && obs[i][0] != 1 ; i++ )
            dp[i][0] = 1;
        for( int j=1 ; j<dp[0].size() && obs[0][j] != 1 ; j++ )
            dp[0][j] = 1;
        
        //Marking squares with obstacles on them as -1
        for( int i=0 ; i<obs.size() ; i++ )
            for( int j=0 ; j<obs[0].size() ; j++ )
                if( obs[i][j] == 1 )
                    dp[i][j] = -1;
        
        //DP
        for( int i=1 ; i<dp.size() ; i++ )
            for( int j=1 ; j<dp[0].size() ; j++ )
            {
                if( dp[i][j] != -1 ) //if current square doesn't hold an obstacle
                {
                    if( dp[i-1][j] != -1 ) //No path can emerge from an obstable square 
                        dp[i][j] += dp[i-1][j];
                    if( dp[i][j-1] != -1 ) //No path can emerge from an obstable square 
                        dp[i][j] += dp[i][j-1];
                }
            }
        
        return max(0, dp[dp.size()-1][dp[0].size()-1]);
    }
};