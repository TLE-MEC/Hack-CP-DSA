class Solution {
  /* 
    we will denote this with 2-D matrix
    where each cell dp[i][j] will correspond to a specific portion of array from i -> j th index
   */
  public int maxCoins(int[] arr) {
    int dp[][]= new int[arr.length][arr.length];
    for(int g=0;g<dp[0].length;g++){ // this will control the gap of the  interval
      for(int i=0,j=g;j<dp[0].length;i++,j++){
        int max=Integer.MIN_VALUE;
        /* 
          We will find the maximum of the all the possible cases of the sub arry from i->j
          if the k th element is the last one being popped from its group of i->j
          for every k we will find this sum.
         */
        for(int k=i;k<=j;k++){
          int left=(i==k)?0:dp[i][k-1];
          int right=(k==j)?0:dp[k+1][j];
          int val=(i==0?1:arr[i-1])*arr[k]*(j==arr.length-1?1:arr[j+1]);
          max=Math.max(max,left+right+val);
        }
        dp[i][j]=max;
      }
    }
    return(dp[0][dp[0].length-1]);
  }
}