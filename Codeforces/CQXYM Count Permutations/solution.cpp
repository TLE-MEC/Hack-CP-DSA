// including needed file for c++
#include <bits/stdc++.h>
#define ll long long
#define ul unsigned long long
#define modu 1000000007
using namespace std;

// declaring test function
void test(void);
// declaring main function
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 // input output
#ifndef ONLINE_JUDGE
    // For getting input from input.txt file
    freopen("input.txt", "r", stdin);

    // Printing the Output to output.txt file
    freopen("Output1.txt", "w", stdout);
#endif

    long long T = 1;
    cin >> T;
    // run for each test cases
    while (T--)
    {
        // calling function
        test();
    }
#ifndef ONLINE_JUDGE
    cout << "\nTime Elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " sec\n";
#endif
    return 0;
}

void test(void)
{
    // taking input 
    ll n;
    cin >> n;
    // here we are using logic that until n>2 means there is atleast 2 value muliply ans with no of element
    n *= 2;
    ll ans = 1;
    while (n > 2)
    {
        ans *= (n);
        ans %= modu;
        n--;
    }
    // print the ans
    cout << ans << endl;
}
