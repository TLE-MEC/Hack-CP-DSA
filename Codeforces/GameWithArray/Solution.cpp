#include <bits/stdc++.h>
#define ll long long
#define db double
#define rep(i, t) for (ll i = 0; i < t; i++)
using namespace std;
void solve1()  //Main function
{
    ll n, s;
    cin >> n >> s;  //Taking inputs
    if (n == 1)  //if n=1 then length of requirred array is 1
    {
        if (s == 1)  // if s=1 then no case possible
            cout << "NO" << endl;
        else
        {
            cout << "YES" << endl;  
            cout << s << endl; 
            cout << s - 1 << endl;  // if s!=1 then k will be s and array element will be s-1
        }
    }
    else
    {
        if (s <= n)  //no case possible when s<=n
        {
            cout << "NO" << endl;
        }
        else
        {
            ll num = s - (n - 1) - 1;
            ll fnum = s - (n - 1);
            bool cond = 0;
            for (int i = 0; i < (n - 1); i++)
            {
                if ((fnum + i) == num||(s-(fnum+i))==num)  //checking for condition
                {
                    cond = 1;
                    break;
                }
            }
            if (cond)  //if the condition statisfies then no answer possible
            {
                cout << "NO" << endl; 
            }
            else
            {
                //Else the array exists with the following solution
                cout << "YES" << endl;
                for (int i = 0; i < (n - 1); i++)
                {
                    cout<<1<<" ";
                }
                cout<<fnum<<endl;  
                cout<<num<<endl;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll t;
    t = 1;
    rep(i, t)
    {
        solve1(); //going to the funnction which solves the problem
    }
    return 0;
}
