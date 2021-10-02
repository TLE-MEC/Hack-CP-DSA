#include <bits/stdc++.h>
#define ll long long
#define ul unsigned long long
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
    while (T--)
    {
        test();
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
    ll m, k;
    cin >> m >> k;
    vector<string> arr(n), brr(n, string(m, '.'));
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.')
                continue;

            ll d = 0;
            while (true)
            {
                if (i - d - 1 >= 0 and j - d - 1 >= 0 and j + d + 1 < m and arr[i - d - 1][j - d - 1] == '*' and arr[i - 1 - d][j + d + 1] == '*')
                {
                    d++;
                }
                else
                    break;
            }
            if (d >= k)
            {
                for (int p = 0; p <= d; p++)
                    brr[i - p][j - p] = brr[i - p][j + p] = '*';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != brr[i][j])
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}