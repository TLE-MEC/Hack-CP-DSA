//Add and Divide program form september starters

#include<bits/stdc++.h>
using namespace std;
using ll=long long;

//making a vector function that contains all the prime factors of a given number

void printPrimeFactors(ll n, vector<ll> &v) {
   //checking if the number is divisible by 2
   while (n%2 == 0){
      //adding 2 to the vector
      v.push_back(2);
      n = n/2;
   }
   
   //checking for the rest of the numbers specialy for the primes
   
   for (ll i = 3; i <= sqrt(n); i = i+2){
      while (n%i == 0){
         //adding the number to the vector
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
   //checking for t test cases
    while(t-->0)
    {
        ll a,b,flag=0;
        cin>>a>>b;
        vector<ll>v;
       //calling the function to check for prime factors
        printPrimeFactors(a,v);
       //checking if the number b is divisible by all the prime factors of number a
        for(ll i=0;i<v.size();i++)
        {
            if((b%v[i])!=0)
            {
                flag=1;
                break;
            }
        }
       //if b is divisible by all the prime factors of a, the flag value will change
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
        //if b is not divisible by all the prime factors of a, the flag value will remain changed
        else
        {
            cout<<"YES"<<endl;
        }
    }
}
