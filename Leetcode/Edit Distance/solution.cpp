/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character 
*/


// You can check over gfg :https://www.geeksforgeeks.org/edit-distance-dp-5/
#include<bits/stdc++.h>
using namespace std;
int dp1[1001][1001];

//Iterative method
int solve(string s,string s1, int n,int m)
{   vector<vector<int>>dp(n+1,vector<int>(m+1));
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0)dp[i][j]=j;
            else if(j==0)dp[i][j]=i;
            else if(s[i-1]==s1[j-1])
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                    //insert dp[i][j-1] element
                    //remove dp[i-1][j] element
                    //replace dp[i-1][j-1] element
                dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }

        }
    }
    return dp[n][m];
}

//Recursive method
int solve2(string s,string s1,int n,int m)
{
    if(n==0)return m;
    if(m==0)return n;
    if(dp1[n][m]!=-1)return dp1[n][m];
    if(s[n-1]==s1[m-1])
    {
        if(dp1[n-1][m-1]==-1)
        {
            return dp1[n][m]=solve2(s,s1,n-1,m-1);
        }
        else{
            return dp1[n][m]=dp1[n-1][m-1];
        }
    }
    else{
        int a,b,c;
        if(dp1[n][m-1]!=-1)
        {
            a=dp1[n][m-1];
        }
        else{
            a=solve2(s,s1,n,m-1);
        }
        if(dp1[n-1][m]!=-1)
        {
            b=dp1[n-1][m];
        }
        else{
            b=solve2(s,s1,n-1,m);
        }
        if(dp1[n-1][m-1]!=-1)
        {
            c=dp1[n-1][m-1];
        }
        else{
            c=solve2(s,s1,n-1,m-1);
        }
        return dp1[n][m]=1+min(a,min(b,c));
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
      string s,s1;
      cin>>s>>s1;
      int n=s.length();
      int m=s1.length();

      //method1
      cout<<solve(s,s1,n,m)<<"\n";

      //initialization of dp using memset
      memset(dp1,-1,sizeof(dp1));

      //method2
      cout<<solve2(s,s1,n,m)<<"\n";
  }
}
