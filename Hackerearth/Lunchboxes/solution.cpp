#include <bits/stdc++.h>
#define int          long long int 
using namespace std; 
 
signed main() 
{ 
    int tc = 1;
    cin>>tc; 
    while(tc--)
    {
        int n,m; cin>>n>>m;
        vector<int> a(m);
        for(int i=0;i<m;i++) cin>>a[i];
        // sort the given array as you need to maximize the number of boxes 
        sort(a.begin(),a.end());
        int ans = 0;
        // traverse through the whole array
        for(int i=0;i<m;i++)
        {
            // if it is possible to give all a[i] boxes, give them all and increment ans and update total lunchboxes
            if(a[i] <= n) 
            {
                ans++;
                n -= a[i];
            }
            // else break
            else break;
        }
        cout << ans << "\n";
    }
 
return 0;
}