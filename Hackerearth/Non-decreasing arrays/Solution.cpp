// NON DECREASING ARRAYS
// TIME COMPLEXITY:- O(N)
// SPACE COMPLEXITY:- O(N)

#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
#define endl "\n"
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vi vector<ll>
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define pii pair<ll,ll>
#define vii vector<pii>
#define vb  vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define calc_fact(n) tgamma(n+1)
#define inf LONG_LONG_MAX
#define MOD 1000000007
#define mod 998244353

signed main()
{
    FIO;

    ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vi A(n),B;
		for(ll i=0;i<n;i++){
			cin>>A[i];
		}
		B.pb(A[0]);
		for(ll i=1;i<n;i++){
			B.pb(((B.back()+A[i]-1)/A[i])*A[i]);
		}
		for(auto it:B){
			cout<<it<<" ";
		}
		cout<<endl;
	}
}
