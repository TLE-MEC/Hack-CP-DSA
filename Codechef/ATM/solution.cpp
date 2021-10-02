// We are given an integer and a double value denoting Pooja's amount to be withdrawn and current bank balance.
// A given amount to be withdrawn is valid only if 
//     - it is a multiple of 5
//     - there is sufficient money in her account to withdraw the money as well as pay $0.50 to the bank as transaction fee.

// if a=amount to be withdrawn and b = total balance
// we will check if a is a multiple of 5 and if (a+0.50)<b:
//     if the condition is satisfied, we return (b-a-0.50) as the remaining balance 
//     else return b 

// NOTE: 
// 1. Since input consists of decimal values, we use double to store ans.
// 2. The answer should have a precision of 2 decimal places, so we need to use setprecision(2)

#include<bits/stdc++.h>
using namespace :: std;

double bankBalance(double a, double b){
	if(b<a+0.500000){
		return b;
	}
	else if(fmod(a,5.0)==0){
		return (b-a-0.500000);
	}
	return b;
	
}

int main(){
	double a=0.0, b=0.0;
	cin>>a>>b;
	double ans=bankBalance(a, b);
	cout<<fixed<<setprecision(2)<<ans;
	return 0;
}
