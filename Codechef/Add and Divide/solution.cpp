#include<bits/stdc++.h>
using namespace std;
using ll=long long;
void printPrimeFactors(ll n, vector<ll> &v) {
   while (n%2 == 0){
      v.push_back(2);
      n = n/2;
   }
   for (ll i = 3; i <= sqrt(n); i = i+2){
      while (n%i == 0){
         v.push_back(i);
         n = n/i;
      }
   }
   if (n > 2)
   v.push_back(n);
}
int main()
{
    ll t;
    cin>>t;
    while(t-->0)
    {
        ll a,b,flag=0;
        cin>>a>>b;
        vector<ll>v;
        printPrimeFactors(a,v);
        for(ll i=0;i<v.size();i++)
        {
            if((b%v[i])!=0)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
}