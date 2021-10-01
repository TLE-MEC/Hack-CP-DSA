#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
     int count=0;
     for(int i=0; i<n-1; i++){
         // If array elements are  equal to zero.
         if(arr[i]==0){
             i++;
         }
         count++;
     }
     cout<<count<<endl;
    return 0;
}
