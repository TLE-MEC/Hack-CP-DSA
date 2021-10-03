#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
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
	    //cout<<a[0]<<" "<<a[1]<<endl;
	    for(int i=0;i<k;i++)
	    {
	        if(a[i]<0)
	        {
	            a[i]=a[i]*(-1);
	        }
	    }
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>0)
	        ans+=a[i];
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
