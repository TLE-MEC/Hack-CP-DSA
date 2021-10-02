/*
Time Complexity : O(32*n) 
Space Complexity : O(1)

Logic : By performing the operation ai=x, aj=y and replacing them with ai= (x AND y),
        aj= (x OR y), where AND and OR are bitwise AND and OR respectively, 
        ***we can shift any set bit of a number at a repective place value to any 
        other number at same place value****.

Step 1: We have to count the number of set bits at each place value of each number.
What does this mean?
eg: We have 4 , 5 and 7 
Binary representation of 4 =>  1  0  0
Binary representation of 5 =>  1  0  1
Binary representation of 7 =>  1  1  1

Count of set bits at each  =>  3  1  2
place value.

Step 2: Initialise ans=0
step 3: As discussed above that we can shift any set bit of a number to any other
        number at same place value, this means that we can create our own numbers.
        As we have to find the maximum square sum of all the numbers so we can 
        create numbers as large as possible.

Step 4: Creating numbers.
        How?? 
        For eg our count of set bits is 3 4 2 1
        so we can create numbers whose binary representation looks like:
        (1 1 1 1), (1 1 1 0), (1 1 0 0), (0 1 0 0);
        which is 15, 14, 12, 4;

Step 5: Calculate their square sum and add it to ans       

*/


#include <bits/stdc++.h>
using namespace std;
#define Input(v, n) fr(i, n) cin >> v[i];
#define sort(v) sort(v.begin(), v.end());
#define int long long int
#define double long double
#define fix(f, n) fixed << setprecision(n) << f
#define endl "\n"
#define pb push_back
#define mp make_pair
#define INF LLONG_MAX
#define mod 998244353


int test,n,a,b;

void solve(){
    cin>>n;

    //taking input
    vector<int>v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }


    vector<int>dp(32,0);
    int nan=0,ans=0;
    
    //Counting number of set bits at each place value
    for(int i=0;i<n;i++){
      for(int j=0;j<32;j++){
         if(1&(v[i]>>j)) dp[j]++,nan=max(nan,dp[j]);
      }
    }
    
    //Creating numbers and adding their square sum to the ans
    for(int i=0;i<nan;i++){
        int temp=0;
        for(int j=0;j<32;j++){
          if(dp[j]!=0) temp+=(1<<j),dp[j]--;
        }
        ans+=(temp*temp); 
    }
    cout<<ans<<endl;
}

int32_t main()
{ 
  //For taking fast input
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  //As we dont have multiple test cases in this question so we took test=1
  test=1;
  while(test--){
    solve();
  }

  return 0;
}
