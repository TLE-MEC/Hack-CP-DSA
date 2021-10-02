/* 
This is a dynamic programming question.
We will use tabulation.
We go fromt the 0th floor to the Nth floor.
*/
class Solution {
  public int superEggDrop(int n, int f) {
    int dp[][] = new int[n+1][f+1]; // Here we are intializing the dp array of the given approach
    // here the rows will represent that number of floors 
    // coulms will represent the number of eggs 
    for(int i=1;i<=n;i++){ // the main motive of stating the loop from second row is that the we have 0 eggs so it is trivail case.
      for(int j=0;j<=f;j++){
        if(j==0) dp[i][j]=0;// if j==0 (number of floor = 0) so inspite of how many eggs we have we dont have to do a single work to find the critical floor.
        else if (j==1) dp[i][j]=1; // if we have only one floor then no matter how many eggs we have we will do that in only a single throw.
        else if(i==1) dp[i][j]=j;// if we have only 1 egg then we will have to throw at every floor to check if it is a critical floor or not.
        else{
          int max=Integer.MAX_VALUE;		
          /* 
            we take minimum of all the maximums(of the cases where from each floor either the egg breaks or egg survies)
            in 1st case we are left with n-1 eggs and f-1 floors to check
            int 2nd case we are left with n eggs with f-k floor to check (k being the current floor);
           */                    
          for(int k=0;k<j;k++) max=Math.min(max,Math.max(dp[i-1][k],dp[i][j-1-k])+1);
          dp[i][j]=max;
        }
      }
    }
    return dp[n][f];
  }
}