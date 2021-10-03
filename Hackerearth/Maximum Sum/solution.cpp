#include <bits/stdc++.h>
#define int          long long int 
using namespace std; 

signed main() 
{ 
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    // sort the array to choose the ans greedily 
    sort(a.begin(),a.end());
    int mx = a[n-1];
    int cnt = 1;
    // now traverse the array from the maximum element and add it to the sum at each step and update the max_sum till now
    // if the sum becomes less than the max_sum we we won't include elements after that as it will decrease the whole sum
    // else increment the count  
    for(int i=n-2;i>=0;i--)
    {
        int sum = a[i] + mx;
        if(sum>=mx)
        {
            mx = sum;
            cnt++;
        }
        else break;
    }
    cout << mx << " " << cnt;

return 0;
}