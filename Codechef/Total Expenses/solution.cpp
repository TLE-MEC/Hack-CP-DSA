// Total Expenses solution in c++
// Author - Keshav Prajapati
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        float q,p;
        cin>>q>>p;
        if(q<=1000)
            cout<<setprecision(6)<<fixed<<q*p<<endl;
        else
            cout<<setprecision(6)<<fixed<<(p-(p*0.1))*q<<endl;
    }
    
	// your code goes here
	return 0;
}
