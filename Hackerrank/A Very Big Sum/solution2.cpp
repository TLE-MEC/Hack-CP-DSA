#include <iostream>
// Defining ull : because a sum of 10 integers can overflow integer range, hence we need to store it in a higher datatype
#define ull unsigned long long
using namespace std;

ull calculateSum(int n){
    ull sum = 0;
    int x;
    for(int i=0; i<n; ++i){
        // Collecting one input element from std::in at a time and adding it to the sum, which eliminates the need to store all the input before calculating the sum
        cin>>x;
        sum += x;
    }
    return sum;
}

int main(){
    int n;
    // Collecting size of the input array 
    cin>>n;
    // Printing the result
    cout<<calculateSum(n);
    return 0;
}