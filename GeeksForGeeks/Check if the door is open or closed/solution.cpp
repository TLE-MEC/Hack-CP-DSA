// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
 //My Code Starts
class Solution {

  public:
    int flip(int n)//funcction to flip the bits of the vector elements
    {
        return n==0?1:0;
    }
    vector<int> adjust(vector<int> v,int i){// function to adjust the elements of the vector
        vector<int> ad;
        for(int k=1;k<=v.size();k++){
         if(k%i==0)
            ad.push_back(flip(v[k-1]));
         else
            ad.push_back(v[k-1]);
        }
        return ad;
    }
    int *checkDoorStatus(int N) {// function to check door status and return array pointer
      vector<int> v(N,0);
      int *arr=new int[N];
        for(int i=0;i<v.size();i++)
        {
        v=adjust(v,i+1);
        }
        for (int i = 0; i <v.size(); i++) {
            arr[i] = v[i];
        }
        return arr;
    
    }
};
//My Code Ends
// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        int* ptr = ob.checkDoorStatus(N);
        for(int i=0 ; i<N ; i++)
            cout<<ptr[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends