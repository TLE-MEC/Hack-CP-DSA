// including all libraries for c++
#include <bits/stdc++.h>
// defining long long
#define ll long long
#define ul unsigned long long
using namespace std;

// creating sieve function to find prime factors of the elements

vector<ll> visited(10000001, 1);
set<ll> ans;
void seive()
{
    visited[0] = 0, visited[1] = 0;
// running a loop upto sqrt(1000)
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
// declaring test function
void test(void);

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
// template for take input from file and print output to file
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("Output1.txt", "w", stdout);
#endif

    long long T = 1;
    cin >> T;
    // running loop for T test cases
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
    // taking input size(n) , no of tricks and time 
    ll n;
    cin >> n;
    ll m, k;
    cin >> m >> k;
    vector<string> arr(n), brr(n, string(m, '.'));
    for (int i = 0; i < n; i++)
        cin >> arr[i];
     // running a loop to check if there is a free space or not . if we found arr[i][j]=='.' then we found a free space
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == '.')
                continue;

            ll d = 0;
        // if free space found then check the diagonals are free or not if free increse to the each diagonals
            while (true)
            {
                if (i - d - 1 >= 0 and j - d - 1 >= 0 and j + d + 1 < m and arr[i - d - 1][j - d - 1] == '*' and arr[i - 1 - d][j + d + 1] == '*')
                {
                    d++;
                }
                else
                    break;
            }
            // if value > k then fill the brr array
            if (d >= k)
            {
                for (int p = 0; p <= d; p++)
                    brr[i - p][j - p] = brr[i - p][j + p] = '*';
            }
        }
    }
    // checking if brr == arr or not
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
