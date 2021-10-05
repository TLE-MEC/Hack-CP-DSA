#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long findMinDiff(vector<long long> a,long long n,long long m){

        /* sort the array to get chocolates in inceasing order */
        sort(a.begin(),a.end());
        /*initialize ans as maximum because we need minimum difference */
        int ans = INT_MAX;

        /*we take group of m chocolates at a time 
        and since they are in increasing order we find the difference 
        between max and min at every step to get min diff by the end*/
        for(int i=0;i<(n-m);i++){
            if(ans > a[i+m-1] - a[i]){
                ans = a[i+m-1] -a[i];
            }
        }

        return ans;
    }
};


// Driver code
int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> a;
        long long x;
        for(long long i=0;i<n;i++){
            cin>>x;
            a.push_back(x);
        }
        long long m;
        cin>>m;
        Solution ob;
        cout<<ob.findMinDiff(a,n,m)<<endl;
    }
    return 0;
}