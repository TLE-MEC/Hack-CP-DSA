#include<iostream>
using namespace std;
int fib(int n) {            // Function to find nth fibonacci number
        if(n==0)            //Base case for recursion
            return 0;
        if(n==1)
            return 1;
        int fi=fib(n-1)+fib(n-2);           //using recursion
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
