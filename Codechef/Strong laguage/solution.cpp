#include <iostream>
using namespace std;

void language()

{
    int n,p,w=0,flag=0;
    char S[1000000];
    cin>>n>>p;
    cin>>S;
    for(int i=0;i<n;i++)
    {
        if(S[i]=='*')
        {
		w++;
        
		if(w==p)
        {cout<<"YES"<<endl;flag++;
        break;}
    	}
        else
        w=0;
    }
    if(flag==0)
    cout<<"NO"<<endl;
    
}

int main() {
    int t;
    cin>>t;
    while(t>0)
    
    {
        language();
        t--;
    }
	// your code goes here
	return 0;
}
