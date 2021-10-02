// Solution for fair rations problem
#include<bits/stdc++.h>
using namespace std;

/*
The idea here is to first check the sum of all the rations distributed
to the people, if the sum is odd, which means that at least any one element
is odd, and even after doing the operation n times, there will be an odd
element which won't make the rations fair, hence the output will be 'NO'
in this case.

Otherwise, we can iterate over the array and increment any odd element and
its next element, since the sum of the array was even, eventually after traversing
through the array, all elements will become even.

A variable will be created in order to store how many loaves are distributed, which
will be incremented by 2 after each increment operation.
*/

int main(){
  int n, s = 0;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++){
    cin>>arr[i];
    s += arr[i]; // Calculating sum of loaves
  }
  if(s % 2 != 0) // Sum of loaves is odd
    cout<<"NO\n";
  else{
    int c = 0; // Initialising number of loaves by 0
    for(int i=0; i<n; i++){
      if(arr[i] % 2 != 0){
        arr[i]++; // Increment operation
        arr[i+1]++;
        c += 2; // Incrementing number of loaves distributed by 2
      }
    }
    cout<<c<<'\n';
  }
  return 0;
}

// Time complexity - O(n)
// Space somplexity - O(1)
