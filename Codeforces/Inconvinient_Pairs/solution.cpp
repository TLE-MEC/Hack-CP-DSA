#include <bits/stdc++.h>
using namespace std;
#define in(x) int x; cin >> x;
#define sin(s) string s;  cin >> s;
#define ll long long
#define lin(x) ll x; cin >> x;
#define vi vector<int>
#define vll vector<ll>
#define si set<int>
#define pb push_back
#define re(i, n) for (int i = 0; i < n; i++)
#define pe(i, a, b) for (ll i = a; i <= b; i++)
#define rre(i, n) for (int i = n - 1; i > -1; i--)
#define mp make_pair
#define pll pair<ll, ll>
#define pii pair<int, int>
#define endl "\n"
#define FAST  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define ninf -INT_MAX
#define inf 100000000000000000
#define mod 998244353
#define x first
#define y second

// function to calculate powers using binary exponentiation
ll p(ll a, ll b)
{
    long long x = 1, y = a;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x * y) % mod;
        }
        y = (y * y) % mod;
        b /= 2;
    }
    return x % mod;
}

// function to find modulo inverse of a number
ll inv(ll a)
{
    return p(a, mod - 2);
}

int main()
{
    FAST
    in(t) 
    while (t--)
    {
        // inputing the values
        in(n)
        in(m)
        in(k)
        vi x(n),y(m);
        vector<pii> cntx(k), cnty(k);
        re(i, n)
            cin >>x[i]; // inputting the values of x coordinates of vertical streets.
        re(i, m)
            cin >>y[i]; // inputting the values of the y-coordinates of horizontal streets.
        re(i, k)
        {
            cin >> cntx[i].x >> cntx[i].y; // the coordinates of the i-th person.
            cnty[i].x = cntx[i].y;
            cnty[i].y = cntx[i].x;
        }

        sort(cntx.begin(), cntx.end()); // sorting the co-ordinates according to increasing x co-ordinate
        sort(cnty.begin(), cnty.end()); // sorting the co-ordinates according to increasing y co-ordinate
        long long cnt = 0;              // final answer
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        re(i, n - 1) // iterating throught the vertical lines
        {
            auto pp = make_pair(x[i + 1], -1);
            // finding the co-ordinate of the person just before x = x[i+1]
            auto up = lower_bound(cntx.begin(), cntx.end(), pp);

            pp = make_pair(x[i], 100000000);
            // finding the co-ordinate of the person just after x = x[i]
            auto down = upper_bound(cntx.begin(), cntx.end(), pp);

            map<int, int> count; // counter to count the number of points whose x coordinate is in the range (x[i],x[i+1]), with key value being their y coordinate
            for (auto it = down; it != up; it++)
            {
                count[it->y]++;
            }

            vll v; // storing the number of points lying on the same horizontal line
            for (auto x : count)
                v.pb(x.y);
            reverse(v.begin(), v.end());

            // counting the number of inconvinient pairs
            if (v.size() > 1)
                pe(i, 1, v.size() - 1)
                {
                    cnt += v[i - 1] * v[i];
                    v[i] += v[i - 1];
                }
        }
        re(i, m - 1) // iterating throught the horizontal lines
        {
            auto pp = make_pair(y[i + 1], -1);
            // finding the co-ordinate of the person just before y = y[i+1]
            auto up = lower_bound(cnty.begin(), cnty.end(), pp);

            pp = make_pair(y[i], 100000000);
            // finding the co-ordinate of the person just after y = y[i]
            auto down = upper_bound(cnty.begin(), cnty.end(), pp);

            map<int, int> count; // counter to count the number of points whose y coordinate is in the range (y[i],y[i+1]), with key value being their x coordinate
            for (auto it = down; it != up; it++)
            {
                count[it->y]++;
            }
            vll v; // storing the number of points lying on the same vertical line
            for (auto x : count)
                v.pb(x.y);
            reverse(v.begin(), v.end());

            // counting the number of inconvinient pairs
            if (v.size() > 1)
                pe(i, 1, v.size() - 1)
                {
                    cnt += v[i - 1] * v[i];
                    v[i] += v[i - 1];
                }
        }
        cout << cnt << endl;
    }
    return 0;
}