#include <bits/stdc++.h>
using namespace std;                                        
#define ll long long int
#define ld long double
 
void solve()
{
    int l,r;
  cin>>l>>r;
  int m=INT_MIN;
  //max modulus we can get from a number is (half of number -1).
  int flag=0;
  //if 2nd number is greater than half we can get a remainder of (half number -1) 
  if(r/2>=l)
  {
      cout<<r%(r/2+1)<<"\n";
  }
  //if   r/2 < l   we can have max remainder of r/l as half-1 is not possible.
  else if(r/2<l)
  {
      cout<<r%l<<"\n";
  }
}
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int  t=1; 
 cin>>t; 
 while(t--) 
 solve();
 return 0;
}