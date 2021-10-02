#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const ll N=2e4;
void solve()
{
    ll n,l,r;
    cin >> n >> l >> r;
    ll mn=LONG_LONG_MAX,base=0;
    if(n>=l && n<=r){
        base=n;
    }
    else if(n<l){
        base=l;
    }
    else{
        while(l<r && n/r<r){
            ll temp1=n/r,temp2=n%r;
            if(mn > temp1+temp2){
                mn=temp1+temp2;
                base=r;
            }
            r = n/(temp1+1);
        }
        while(l<=r){
            ll temp3=n,sum=0;
            while(true){
                if(temp3<l){
                    sum+=temp3;
                    if(sum<mn){
                        mn=sum;
                        base=l;
                    }
                break;
                }
                sum += temp3%l;
                temp3 /=l;
                if(sum>=mn){
                    break;
                }
            }
            l++;
        }
    }
    cout<<base<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#ifndef ONLINE_JUDGE
///	freopen("input.txt", "r", stdin);
///	freopen("output.txt", "w", stdout);
#endif

    ll test=1;
    cin>>test;
    while(test--)
    {
        solve();
    }
    return 0;
}
