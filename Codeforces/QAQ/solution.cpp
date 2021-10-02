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

/////////////////////////////////////////////

int main()
{
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            for (int k = j + 1; k < s.size(); k++)
            {
                if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
                {
                    ans += 1;
                }
            }
        }
    }
    cout << ans << endl;
}
