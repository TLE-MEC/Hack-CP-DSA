#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
-> Here we dont need the Y co-ordinates.

-> Sort the X co-ordinates.

-> From X[i] find till which index you can cover point with the first platform. let's call this index pos. You can do binary search

-> then find the maximum points you can cover with the second platform after the pos index. but how to find this?

-> Start from the last point. every time at ith index store what is the maximum points you can cover after the current index
*/

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    sort(x.begin(), x.end());
    vector<int> mx(n, 0);
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        int val = x[i] + k;
        int pos = (upper_bound(x.begin(), x.end(), val) - x.begin());
        pos--;

        int first_platform = pos - i + 1;
        int second_platform = 0;
        if (pos < n - 1) {
            second_platform = mx[pos + 1];
        }

        ans = max(ans, first_platform + second_platform);
        mx[i] = first_platform;
        if (i != n - 1)
            mx[i] = max(mx[i], mx[i + 1]);
    }
    cout << ans << '\n';
}

int32_t main() {
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
