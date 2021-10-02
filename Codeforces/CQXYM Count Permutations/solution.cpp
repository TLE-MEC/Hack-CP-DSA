#include <bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define modu 1000000007
using namespace std;

vector<ll> visited(10000001, 1);
set<ll> ans;
void seive()
{
    visited[0] = 0, visited[1] = 0;

    for (int i = 2; i * i < 1000; i++)
    {
        if (visited[i])
        {
            ans.insert(i);
            for (int j = i * 2; j < 1000; j += i)
            {
                visited[j] = 0;
            }
        }
    }
}
void test(void);
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("Output1.txt", "w", stdout);
#endif

    long long T = 1;
    cin >> T;
    // ll k = 1;
    // seive();
    while (T--)
    {
        // cout << "Case #" << k << ": ";
        // print(T);
        test();
        // k++;
    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
    return 0;
}

void test(void)
{
    ll n;
    cin >> n;
    n *= 2;
    ll ans = 1;
    while (n > 2)
    {
        ans *= (n);
        ans %= modu;
        n--;
    }
    // ans /= 2;
    // cout << "TGASD\n";
    cout << ans << endl;
}