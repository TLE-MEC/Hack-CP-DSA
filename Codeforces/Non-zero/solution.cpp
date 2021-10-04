#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;

    long long int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    long long int s = 0, ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)          //if a[i]=0 then adding 1 to final answer and sum
            ans++, s++;
        else
            s += a[i];         //else simply adding element to sum variable
    }

    if (s == 0) ans++;        //If overall sum is still 0 then increment answer

    cout << ans << endl;
}

int main()
{
    long long int tt = 1;
    cin >> tt;
    while (tt--)
        solve();

    return 0;
}