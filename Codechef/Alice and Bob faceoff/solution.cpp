//here as both the players play optimally so we can see that 
/*
Problem =>>> Greedy

By checking the optimal outcomes at some of the n value we can see that
1. if n is even then Alice will win only condition where bob wins is when (n+2) is power of two
2. if n is odd then Bob will win only condition where alice wins is when (n+1) is power of two
*/


#include <bits/stdc++.h>
using namespace std;

#define ll long long

//this program is used to check whether the number is power of two or not as 
// no that are pow of 2 has only 1 bit
// so ex for 8 = 1000 and 7 = 0111 so 7 & 8  == 0

bool powOfTwo(ll n){
 return !(n & (n-1));
}

int main() {
	// your code goes here
	ll t;
	cin>>t;
	while(t--){
	    ll n;
	    cin>>n;
	    
	    if(n%2==0)
	    powOfTwo(n+2)?cout<<"Bob\n":cout<<"Alice\n";//if even and (n+2) power of 2 then bob wins else alice wins at rest all even n
	    else
	    powOfTwo(n+1)?cout<<"Alice\n":cout<<"Bob\n";//if odd and (n+1) power of 2 then alice wins else bob wins at rest all odd n 
	}

	return 0;
}