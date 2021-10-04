class Solution {
  public int numTrees(int m) {
    /* Since all the number are in increaseing order 
        we are left with the fact the each number numbered from 1->n can be the root of the number 
        so we have for every n number of binary tress at the left which combine with number of trees in the right to form a unique tree
     */
    int dp[]=new int[m+1];
    dp[0]=1; // even with 0 element only 1 tree can be formed that is NO TREE!!!! n^0=1 take analogy from that.
    dp[1]=1; // with 1 node only 1 tree could be formed.
    for(int i=2;i<dp.length;i++){
      for(int j=0;j<i;j++) dp[i]+=dp[i-1-j]*dp[j];
      // if j is the node then for the left contains the number of b-trees which have elemnts lesser than j  ;
      // if j is the node then for the right contains the number of b-trees which have elemnts greater than j ;
    }
    return dp[dp.length-1];
  }
}