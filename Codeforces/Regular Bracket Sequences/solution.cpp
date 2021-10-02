/*

Time Complexity : O(n)
Space Complexity : O(1)

Logic ---
We should print n different regular bracket sequences of length 2*n
How can we do this?? 

Take t=0;

Then iterate through the below given steps **** n number of times ****

step 1: t++
step 2: print '(' t times 
step 3: print ')' t times
step 4: print "()" (n-t) times ==> lenght = 2*(n-t)
step 5: lenght = t + t + 2(n-t) = 2*n (which is the required length)

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
#define mod 1000000007


int test,n;

void solve(){
  cin>>n;
  int t=1;
  for(int i=0;i<n;i++){
       for(int j=0;j<t;j++) cout<<'(';
       for(int j=0;j<t;j++) cout<<')';
       for(int j=t;j<n;j++) cout<<"()";
       cout<<endl;
       t++;
  }
}

int32_t main()
{ 
  
  //For taking fast input 
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  

  // "test" stores the number of test cases
  cin>>test;
  while(test--){
    solve();
  }

  return 0;
}
