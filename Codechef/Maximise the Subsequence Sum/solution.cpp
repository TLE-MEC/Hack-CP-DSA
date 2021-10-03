// basically what we need is max subsequence array sum
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;cin>>t;
	while(t--)
	{
	    int n,k;cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    } 
	   sort(a,a+n);
	    // after sorting the array we are choosing K negative element in the array and multiplying it with '-1' to make it positive one
	    for(int i=0;i<k;i++)
	    {
	        if(a[i]<0)
	        {
	            a[i]=a[i]*(-1);
	        }
	    }
		// initilized variable ans for storing max subsequence array sum
	    int ans=0;
		// using this loop we are adding all the positive element in the array to get max subsequence array sum
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>0)
	        ans+=a[i];
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
