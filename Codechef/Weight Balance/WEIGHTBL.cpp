#include <iostream>
using namespace std;
int weight()
{
    int w1,w2,x1,x2,M;
    cin>>w1>>w2>>x1>>x2>>M;
    
    if((w2-w1>M*x2)||(w2-w1<M*x1))
    return 0;
    else
    return 1;
}

int main() {
	// your code goes here
	int t,q;
	cin>>t;
	while(t>0)
	{
	    cout<<weight()<<endl;
	    t--;
	}
	return 0;
}
