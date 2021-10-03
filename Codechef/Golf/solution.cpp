#include <iostream>
using namespace std;

int main() {
    //Taking number of test cases.
    int testcases;
    cin>>testcases;
    while(testcases--)
    {
       //Taking the values for N, x, k for each test case.
       int N,x,k;
       cin>>N>>x>>k;
       //Checking if ball will fall into x in lengths of k being shot either from first tile or last.
       //if location is x in forward journey, then it becomes N+1-x in the backward journey.
       if(x%k==0 or (N+1-x)%k==0)
           cout<<"YES\n";
       else
           cout<<"NO\n";
    }
    return 0;
}