#include<iostream>
using namespace std;
int fib(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        int fi=fib(n-1)+fib(n-2);
        return fi;
    }
int main()
{
    int n;
    cout<<"Enter number"<<endl;
    cin>>n;
    cout<<n<<"th"<<" Fibonacci number is "<<fib(n);
    return 0;

}