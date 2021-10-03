/*
Just by simple observation in case of three digits numbers we can conclude that
the maximum answer for the question is 2 so that means we cannot leave more than 2 digits in the number satisfying notprime condition
also we have to remove maximum digits so first we will search for single digits composite numbers
and then for two digits composite numbers by simple bruteforce
*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define init(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, a, b) for (int i = a; i < b; i++)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define all(a) a.begin(), a.end()
using namespace std;

void solve()
{
    ll a;     //number of digits in number
    string b; //storing the number in string form
    cin >> a >> b;
    V<ll> v;
    ll n = b.length();
    reverse(all(b));
    loop(i, 0, n)
    {
        ll dig = b[i] - '0';    //digit at ith place of number
        if ((dig % 2 == 0 && dig != 0 && dig != 2) || dig == 9 || dig == 1) //if any of the digit is equal to 4,6,8,9 or 1 then all digits except this one can be removed as these are single digit composite numbers
        {
            cout << 1 << "\n"
                 << dig << "\n";
            return;
        }
        loop(j, i + 1, n) //else we search for two digits composite number with ones digit dig
        {
            ll b_temp = b[j] - '0';
            ll no = b_temp * 10 + dig;
            if (no % 2 == 0 || no % 3 == 0 || no % 5 == 0 || no % 7 == 0)
            {
                v.pb(no); //storing the two digit number to be left
                break;
            }
        }
    }
    cout << 2 << "\n"
         << v[0] << "\n";
}

int main()
{
    int t = 0;
    cin >> t;   //number of test cases
    while (t--)
    {
        solve();
    }
    return 0;
}