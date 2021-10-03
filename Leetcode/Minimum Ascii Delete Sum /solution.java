class Solution {
  public static void print(int [][]dp){
      for(int i=0;i<dp.length;i++){
          for(int j=0;j<dp[0].length;j++){
              System.out.print(dp[i][j]+" ");
          }
          System.out.println();
      }
  }
  public int minimumDeleteSum(String s1, String s2) {
      int l1=s1.length();
      int l2=s2.length();
      int dp[][] = new int[l1+1][l2+1];
      // last column or row will signify an empty string.
      // we will solve the question from the bottom right corner to the left most corner
      for(int i=l1;i>=0;i--){
          for(int j=l2;j>=0;j--){
              if(i==l1 && j==l2) dp[i][j]=0; // if the string is empty then we cant delete anything from the string
              else if(i==l1) dp[i][j]+=dp[i][j+1]+(int)s2.charAt(j); // s1 is empty and to make s2 equal to s1 we need to remove all the character from s2
              else if(j==l2) dp[i][j]+=dp[i+1][j]+(int)s1.charAt(i); // s2 is empty and to make s1 equal to s1 we need to remove all the character from s1;
              else{
                 if(s1.charAt(i)==s2.charAt(j)){// if the character are equal then we put the sum when exculding both the same character form s1,s2;
                    dp[i][j]=dp[i+1][j+1];
                 }else{
                      // if they are unequal then we just take the minimum when removing the latest letter of s1 while keeping the s2 intact and the other way around.
                     int down=(int)s1.charAt(i)+dp[i+1][j];
                     int right=(int) s2.charAt(j)+dp[i][j+1];
                     dp[i][j]=Math.min(down,right);
                 }
              }
          }
      }
      return dp[0][0];
  }
}