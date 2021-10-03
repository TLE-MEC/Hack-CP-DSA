class Solution {
  int tl=0; // jsut to store the total number of elemenst;
  int dp[][]; // memoization array
  public int rec(int n,int si,int ei,int[]cuts){
      if(ei<=si) return 0; // return base case
      int ans=Integer.MAX_VALUE;
      if(dp[si][ei]!=0) return dp[si][ei];
      for(int i=si;i<ei;i++){
        // Main Idea is that we will looop through the whole cuts arrays
        // and for every index will find the left and right index for the cuts
        // the cost for the present cut is the difference of rEnd-lEnd;

          int le=(si==0)?0:cuts[si-1];
          int re=(ei==cuts.length)?tl:cuts[ei];
          int sl=re-le;
          int lf= rec(le,si,i,cuts); // finding the minium cost for for the left half of the array;
          int rf= rec(re,i+1,ei,cuts); // finding the minium cost for the right half of the array.
          ans=Math.min(ans,sl+lf+rf);
      }
      // NOTE: we are looping for the cuts arrys so we have to finally make other calls when ever we incur another possible area where
      // we can cut the array;
      // This confused me a lot so after a lot of dry running i was able to get the concept clear.
      // so Take you time.
      return dp[si][ei]=ans;
  }
  public int minCost(int n, int[] cuts) {
      dp = new int[cuts.length+1][cuts.length+1];
      tl=n;
      Arrays.sort(cuts);
      return rec(n,0,cuts.length,cuts);
  }
}