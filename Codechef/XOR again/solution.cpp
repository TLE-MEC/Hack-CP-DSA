/*
c++ code of xor again question in codechef beginners
*/
#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int x=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[n];
            x=x^arr[n];
        }
        cout<<2*x<<endl;
    }
}
