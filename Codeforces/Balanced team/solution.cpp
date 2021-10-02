#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int n;
    cin>>n;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    sort(ar,ar+n);
    int ans=0;
	int j=0;
	for (int i=0;i<n;++i) {
		while (j<n&&ar[j]-ar[i]<=5) {
			j++;
			ans=max(ans,j-i);
		}
	}
    cout<<ans<<endl;
}
