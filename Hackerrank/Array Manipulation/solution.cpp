/*
What we do is add the number 'k' to the element at index 'a'(i.e a-1 in terms of actual index) 
and subtract it from element at index 'b' (which we do not decrement by 1. Why? explained later)
By doing this we emulate the operation of adding 'k' to each element belonging to indexes [a-1, b)
i.e elements from 'a-1' to 'b-1' will be greater by 'k' and from 'b' onwards will be smaller by 'k'
(That's why, 'b' is not decremented by 1 and 'k' is subtracted from arr[b])
This emulation speeds up the manipulation and prevents redundant operations.

In short, prefix sum  array approach is used.

Time complexity: O(n)
Space complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    //first 2 lines to perform fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long n,m,a,b,k;
    cin>>n>>m;
    vector<long> arr(n+1);  //required array size 
    
    //for loop to get the values of a,b,k and compute prefix sum array
    for(long i=0; i<m; i++){
        cin>>a>>b>>k;   //take input a,b,k
        a=a-1;          //because index of arr starts from 0 and the given value 'a', will always be +1 of actual index
        arr[a] += k;    //adds 'k' to the integer present at index 'a'
        arr[b] -= k;    //subtracts 'k' from the integer present at index 'b'
    }
    
    long long max_val = 0;          //to store the maximum value present in array
    long long running_count =  0;   //to store the sum

    //for loop to scan maximum value
    for(long i=0; i<n; i++){
        running_count += arr[i];    //add all values in cumulative way
        if(running_count > max_val) 
            max_val=running_count;
    } 
    cout<<max_val<<" ";
    
    return 0;
}
