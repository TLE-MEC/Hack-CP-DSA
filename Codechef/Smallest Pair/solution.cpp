#include <bits/stdc++.h>
using namespace std;


int main() {
    long long int t,n,a[1000000],small=INT_MAX,i,small2=INT_MAX;
	cin>>t; //input no of test cases
	while(t--)
	{
        //input array size
	    cin>>n;
	    for(i=0;i<n;i++){
	        cin>>a[i];
	        
	    }
        //sorting the array
	    sort(a,a+n);
        //the top 2 elemetns will be smallest and hence their sum will be also the smallest
	cout<<a[0]+a[1]<<endl;
}return 0;
}