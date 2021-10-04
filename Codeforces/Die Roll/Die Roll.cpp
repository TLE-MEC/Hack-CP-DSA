#include<bits/stdc++.h>
using namespace std;
int main()
{
     ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int a,b;
 cin>>a>>b;// take input of max amount of both or if same any one of their die value
 int m=max(a,b);
 int r=6-m+1; // to get 1 more or equal she has  6 - max +1 ways to win
 // if she needs 5 or more she has  5,6 output needed which is number of ways == 6-5+1 =2

 int z=__gcd(r,6); // to print in lowest fraction we take gcd
 cout<<r/z<<"/"<<6/z;
 
 return 0;
}