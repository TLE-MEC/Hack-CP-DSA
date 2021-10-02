/* As we can see we have to find the base which lies between l and r
According to the contraints, we have to divide this problem into three parts
1) if n<l then sum of remainder of n base l or n base r is gonna be same
2)if l<n<r then n will be the answer cause the n base n is always gonna give sum 1
3)if n>l and n>r
    then we also again subdivide the problem
    by a)if r is greater than square root of n then we can make two digit case better by ignoring all the the bases producing the same first digit.
    b) else test case - by following th actual function given in the problem
    
    
*/
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
//     Case 1
    if(n>=l && n<=r){
        base=n;
    }
// Case 2
    else if(n<l){
        base=l;
    }
// Case 3
    else{
// Subcase 1
        while(l<r && n/r<r){
            ll temp1=n/r,temp2=n%r;
            if(mn > temp1+temp2){
                mn=temp1+temp2;
                base=r;
            }
            r = n/(temp1+1);
        }
// Final else case
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
