#include <iostream>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	    int M, N ,K;
	    cin>>M>>N>>K;
	    
	    if(N*K<M)
	    cout<<"YES\n";
	    else
	    cout<<"NO\n";
	}
	return 0;
}
