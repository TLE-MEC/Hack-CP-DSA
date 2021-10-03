//Given 'n' we need to print an intresting pair of arrays.
//If n is not divisible by 4 then no intresting pair is possible.
//We can get an intresting pair of arrays by:
//Taking the first n/4 and last n/4 integers upto n as first array.
//And then the remaining middle integers as the second array.
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)        
	{
	    int n;
	    cin>>n;
	    if(n%4!=0)                  //When is n is not divisible by 4 an intresting pair cannot be formed
	        cout<<"NO\n";
	    else
	    {
	        cout<<"YES\n";                      
	        for(int i=1;i<=n;i++)       
	        {    
                if(i>n/4 && i<n+1-n/4)  //This condition ensure that only the first and last n/4 integers are printed.
                    continue;          
                cout<<i<<" ";
            }
	        cout<<"\n";
	        for(int i=n/4+1;i<=n-n/4;i++) //Print remaining middle integers
	            cout<<i<<" ";
	        cout<<"\n";
	    }
		
			
	}
	return 0;
}