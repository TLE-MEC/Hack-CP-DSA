#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long int ull;
typedef long double ldb;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define pb push_back
#define pf push_front
#define popb pop_back()
#define popf pop_front()

#define rep(i, m, n) for (ll i = m; i < n; i++)
#define repi(i, n) for (int i = n - 1; i >= 0; i--)

#define deci(n) fixed << setprecision(n)
#define high(n) __builtin_popcount(n)     //no. of ones in set bits
#define highll(n) __builtin_popcountll(n) //no. of ones in set bits (ll)
#define parity(n) __builtin_parity(n)     //odd parity->true else false
#define clz(n) __builtin_clz(n)           //clz = count leading zero’s
#define clzll(n) __builtin_clzll(n)       //clz = count leading zero’s (ll)
#define ctz(n) __builtin_ctz(n)           //ctz = count trailing zeros
#define all(v) v.B, v.E
#define S size()
#define E end()
#define B begin()
#define L length()

#define mod1 1000000007
#define mod2 998244353
#define INF LLONG_MAX
#define PI 3.1415926535897932384

#define gcd __gcd
#define search binary_search //bool
#define lol ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"



int main()
{
    ll n;
    cin >> n; // Bank balance
    vector<ll> arr(5);
    ll x = n;
    ll sum = 0;
    ll i = 0, ans = 0;
    arr[0] = 100;
    arr[1] = 20;
    arr[2] = 10;
    arr[3] = 5;
    arr[4] = 1; 
    // arr -> [100,20,10,5,1]
    while (x > 0)
    {
        ll q = x / arr[i]; // maximum no. of arr[i] currency
        x -= arr[i] * q; // rest money left
        ans += q; // adding 
        i++;
    }
    cout << ans << endl;
}
