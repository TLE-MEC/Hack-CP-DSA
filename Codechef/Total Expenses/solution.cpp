/*
Total Expenses solution in c++
Auhtor - Keshav Prajapati
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        float q,p;//q = quantity, p = purchases
        cin>>q>>p;
        if(q<=1000)
            cout<<setprecision(6)<<fixed<<q*p<<endl;//setprecision : set values after decimal
        else
            cout<<setprecision(6)<<fixed<<(p-(p*0.1))*q<<endl;//10% discounted price
    }
	return 0;
}
