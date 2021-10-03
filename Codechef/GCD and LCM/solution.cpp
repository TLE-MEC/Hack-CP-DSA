// In this problem we are given two integers a and b and we need to find the GCD as well as LCM of the two numbers.

// The GCD can be calculated optimally using the euclidean algorithm:
//     GCD(a, b) = GCD(b, a%b) and GCD(a, 0) = a;

// Further, the LCM can be obtained from GCD using the following relation:
//     LCM(a, b)*GCD(a, b) = (a*b);

// TIME COMPLEXITY: O(log(n))
// SPACE COMPLEXITY: O(1);

#include<bits/stdc++.h>
using namespace :: std;

int gcd(int a, int b){
    if(b==0) return a;

    return gcd(b, a%b);
}

void GCDLCM(int a, int b){
	int GCD=gcd(a, b);
	long long LCM=(long long)a*b;
	LCM=LCM/GCD;
	cout<<GCD<<" "<<LCM<<endl;
	return;
}

int main(){
	int t=0;
	cin>>t;
	while(t--){
		int a=0, b=0;
		cin>>a>>b;
		GCDLCM(a, b);
	}
	return 0;
}
