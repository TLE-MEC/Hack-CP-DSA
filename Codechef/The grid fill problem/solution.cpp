#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;cin>>t;
	while(t--)
	{
	    int n;cin>>n;
	    int a[n][n];
        // there is basically 2 cases 1st is when n=2,print all element as negative
	    if(n==2){
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cout<<-1<<" ";
	        }
	        cout<<endl;
	    }
	    }
        // in 2nd case print diagonally negative
	    else{
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	           if(i==j) 
	           cout<<-1<<" ";
	           else
	           cout<<1<<" ";
	        }
	        cout<<endl;
	    }
	    }
	}
	return 0;
}