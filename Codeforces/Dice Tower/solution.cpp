/*
Just think sum of opposite sides of a dice is always 7 
this implies sum of visible part are always 14 since there are other 4 besides top and bottom.

For top-most die, numbers on the sides give a sum of 14.
We can see that there is one extra top side in case of top-most dice.

so if there is n dice from bottom to top.
besides top-most one 4 sides of others are visible and sum is 14*(n-1)
so when it comes to top-most dice 14+(top )

so overall sum is sum=14*(n-1)+14+top which is sum=14*n+top

here top belongs to {1,2,3,4,5,6}
so sum%14 should belongs to set {1,2,3,4,5,6}

exceptional case n/14 shouldn't be zero i.e n>14 

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	ll t;
	cin>>t;
	while(t--){
		ll sum;
		cin>>sum;
		if(sum%14>6||sum/14==0||sum%14==0)cout<<"NO\n";
		else cout<<"YES\n";
	}
	return 0;
}
