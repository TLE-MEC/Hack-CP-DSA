//Problem Link: https://codeforces.com/contest/1467/problem/A
#include <bits/stdc++.h>

#define For(i, l, r) for (int i = l; i <= r; i++)
#define fo(i, n) for (int i = 0; i < (n); ++i)
#define INF 1000000000000000000
#define MOD 1000000009;

using namespace std;
using ll = long long;
using ld = long double;

void solve(ll n)
{
    string ans = "";
    int d = 9;
    // If there is only one panel, then pause it when digit 9 appears on it.
    if (n == 1)
    {
        cout << "9";
        return;
    }
    ans = "98";
    // it is always optimal to pause the second panel from left, when the digit 8 appears on it.
    // This would give an answer of the form 98901234567890123456….
    // You can verify that this is the largest number that can be achieved.
    for (int i = 2; i < n; i++)
    {
        ans += to_string(abs(d++) % 10);
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        solve(n);
        cout << '\n';
    }
    return 0;
}