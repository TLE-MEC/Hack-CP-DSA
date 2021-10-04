#include <bits/stdc++.h>
#define int long long int
using namespace std; 

signed main() 
{ 
    int tc = 1;
    cin>>tc; 
    while(tc--)
    {   
        int n,x,y; cin >> n >> x >> y;
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        // use the concept of sliding window
        multiset<int> st;
        // insert the first y elements into multiset for the first window
        for(int i=0;i<min(n,y);i++) st.insert(a[i]);
        int ans = min(n,y);
        int j = min(n,y);
		int prev = 0;
        while(j < n)
        {
            // if the size of multiset is less than max size of subsegment insert the element
            if(st.size() < y)
            {
                st.insert(a[j]);
				j++;
                continue;
            }
            // else check if the sum of minimum elements are less than max_sum
            st.insert(a[j]);
            int tot = 0; 
			int sum = 0;
            for(auto it:st)
            {
                if(tot == st.size()-y) break;
                sum += it;
                tot++;
            }
            // if sum is greater than max_sum remove the prev element
            if(sum > x)
            {
				st.erase(st.find(a[prev]));
				st.erase(st.find(a[j]));
				prev++;
            }
            // if sum is less then add the given element in window and update the max length
            else
            {
				if((j - prev + 1) > ans) ans = j - prev + 1;
                j++;
            } 
        }
        cout << ans << "\n";
    }

return 0;
}
