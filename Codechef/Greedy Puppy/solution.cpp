/*
Greedy Puppy solution in c++
Auhtor - Keshav Prajapati
*/

#include <iostream>
using namespace std;

int main() {
    int t,n,k,cal;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int coin=0;
        cin>>n>>k;
        for(int j=1;j<k+1;j++)
        {
        cal=n%j;
        if(cal>coin)
        coin=cal;
        }
        cout<<coin<<endl;
    }
	// your code goes here
	return 0;
}