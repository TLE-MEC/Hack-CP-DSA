// Here, we have an array of pow(2, n) integers starting from 0 to pow(2, n)-1.
// We need to make swaps so that the sum of XOR of element with its index for the whole array is maximum.

// Initially, since each index stores a number equal to its index, the value of sum = 0. (a^a=0, where ^ denotes XOR)
// This question can be solved in O(1) time if we make the following observation:

// We know XOR of two numbers is maximum if they are complements of each other in bit representation.
// Consider the following case:

// n=3
// arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
// in the binary representation,
// arr[] = {000, 001, 010, 011, 100, 101, 110, 111};

// we can see that the ith element from the beginning is the complement of ith element from the end.
// ex- 7 and 0 are complements, 6 and 1 are complements, and so on...

// for each swap made between these elements, the resulting XOR we would get at each index would be pow(2,n)-1

// suppose we make 2 swaps in the above case so that the array becomes

//             idx: 0 1 2 3 4 5 6 7
// 			arr: 7 6 2 3 4 5 1 0
// 	  XOR value: 7 7 0 0 0 0 7 7

// Hence, we arrive at the following conclusion:

// for any given n, if k<(pow(2,n)/2) then we will make k swaps to get 2*(pow(2,n)-1) with each swap.
// 				 therefore, ans = 2*(pow(2, n)-1)*k

// 				 otherwise, we will make (pow(2, n)/2) swaps to generate max result
// 				            ans = 2*(pow(2, n)-1)*(pow(2, n)/2)


// TIME COMPLEXITY: O(1)
// SPACE COMPLEXITY: O(1)

// NOTE: Since answer may exceed the limit for int, use long long int.

#include<bits/stdc++.h>
using namespace :: std;
#define ll long long 

ll solve(ll n, ll k){
	ll a = 1<<n;
	if(k>=(a/2)){
		return 2*(a/2)*(a-1);
	}
	
	return 2*k*(a-1);
}

int main(){
	ll t=0;
	cin>>t;
	while(t--){
		ll n, k=0;
		cin>>n>>k;
		cout<<solve(n, k)<<"\n";
	}
	return 0;
}