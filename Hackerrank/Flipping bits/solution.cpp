#include<iostream>

using namespace std;

int main(){
    long long int t; 
    cin>>t; // Taking input of number of testcases
    while(t--){
    long long int n; // Temp variable to store the testcases
    cin>>n;
    long long int a= 4294967295-n; // Flipping the bits
    cout<<a<<endl; // Printing the solution
    }
}
