#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t, n, m, d, D, max, i, j, xtra, leftover;
	vector<int> edges;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m>>d>>D;
		//your code goes here
	    if( m<n*d )
	        cout<<-1<<endl;
	    else if( m>=n*d )
	    {
	        max = d + (m-n*d)/n;
	        if( (m-n*d)%n > 0 )
	            max++;
	        if( max > D )
	            cout<<-1<<endl;
	        else
            {
    	        edges.resize(m);
                for(i=0;i<n;i++)
                    edges[i] = d;
                xtra = (m-n*d)/n;
                for(i=0;i<n;i++)
                    edges[i] += xtra;
                leftover = (m-n*d)%n;
                for(i=0;i<leftover;i++)
                    edges[i]++;
                
                for(i=0;i<n;i++)
                {
                    for(j=0;j<edges[i];j++)
                        cout<<i+1<<" "<<(i+j)%n+1<<endl;
                }
            }
	    }
	}
	return 0;
}
