#include <bits/stdc++.h>
using namespace std;

int fact_preceeding_zeros(long int x)
{
    long int var;
    cin >> var;

    if (var < 0)
    {
        return -1;
    }

    long int c = 0;

    for (long int i = 5; (var / i) > 0; i = (i * 5))
    {
        c = c + (var / i);
    }
    return c;
}

int main()
{
    long int tc;
    cin >> tc;

    while (tc--)
    {
        cout << fact_preceeding_zeros(tc) << endl;
    }
    return 0;
}