#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define fio               ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int               long long
#define vi                   vector<int>
#define pb                push_back
#define mii               map<int,int>
#define all(x)         (x).begin(),(x).end()
#define endl           '\n' 
#define rep(i,a,b)     for(int i=a;i<b;i++)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pii               pair<int,int>
#define pno            cout<<"NO"<<endl
#define pys            cout<<"YES"<<endl
#define fi                first
#define se                second
#define mp                make_pair
#define sz(x)          (int)((x).size())
#define inf               1e18
#define ld             long double
#define ps(x,y)        fixed<<setprecision(y)<<x

const int mod=1e9+7;//998244353;
const int MAX=1e6;


void solve()
{
    fio;
    int n,x;cin>>n>>x;
    int cnt=0;
    int num=n;
    int i=31;
	if(num<=x)
	{
		cout<<1<<endl;
		return;
	}
    if(x==0 && n%2)
    {
        cout<<-1<<endl;
        return;
    }
	while(num>x)
    {
        for(;i>=0;i--)
        {
            if(num&(1<<i))
            {
                if(i%2)
                num-=(1<<i);
                else if(i-1>=1)
                num-=(1<<(i-1));
                cnt++;
			}
		}

		if(cnt>40)
	    {
            cout<<-1<<endl;
            return;
	    }
    }
    cout<<cnt<<endl;

    return;
}


int32_t main(){
    fio;
    int t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}