//ATM Problem code : HS08TEST
#include <bits/stdc++.h>
using namespace std;

int main() {
    double y;
    int x;
    cin>>x;
    cin>>y;
    if((x+0.50<=y)&&(x%5==0))
    {
        cout<<setprecision(2)<<fixed<<y-(x+0.50);
    }
    else
        cout<<setprecision(2)<<fixed<<y;
	// your code goes here
	return 0;
}
