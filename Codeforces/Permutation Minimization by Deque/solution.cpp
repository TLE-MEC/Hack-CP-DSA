#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        cin>>n;                                     // Input permutation size 
        int arr[n];                                 // Declare an array of given size
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];                            // Store the input into the array
        }
        deque<int>ans;                              // Declare a deque with name ans
        ans.push_back(arr[0]);                      // Insert the first element of the array in deque
        for(int i = 1 ; i < n ; i++){
            if(arr[i] < ans.front()){
                ans.push_front(arr[i]);             // If element of the input array is less than the current front element of the deque then push it in the front
            }
            else{
                ans.push_back(arr[i]);              // Else push it at the back of the deque
            }
        }
        for(auto it:ans){
            cout<<it<<" ";                          // Transverse and print all elements of the deque.
        }
        cout<<"\n";
    }
return 0;
}  