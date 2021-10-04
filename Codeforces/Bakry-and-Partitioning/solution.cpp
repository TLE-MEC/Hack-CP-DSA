#include<bits/stdc++.h>

#define ll long long
#define vll vector<long long>
#define vvi vector<vector<int>>

/*
    First we calculate xor of each subtree using simple recursive dp

    if dp[root] == 0, then removin any edge would give equal xor values on each subtree
    
    if dp[root] != 0, then this dp[root] value would be the xor_value of each subtree
    
    We search for each subtree with this dp[root] value and find answer accordingly
*/

using namespace std;

int n, k;
vll a;
vvi g;
vll xor_val, dp;

// dfs for calculating xor values of each subtree
void dfs_xor(int par, int anc = -1)
{
    xor_val[par] = a[par];
    for(int e: g[par])
    {
        if(e == anc) continue;
        dfs_xor(e, par);
        xor_val[par] ^= xor_val[e];
    }
}   

int pos;

// dfs for finding answer
void dfs(int par, int anc = -1)
{
    for(int e: g[par])
    {
        if(e == anc) continue;
        dfs(e, par);
        dp[par] += dp[e];
    }

    if(dp[par] > 1) pos = 1;

    if(par && xor_val[par] == xor_val[0])
    {
        dp[par]++;
    }

    if(!xor_val[par] && dp[par]) pos = 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin>>test_cases;
    
    while(test_cases--)
    {
            
        cin>>n>>k;
        
        k--;

        a.assign(n, 0);
        for(ll &e: a) cin>>e;

        g.assign(n, {});

        for(ll i =0 ;i < n - 1;i++)
        {   
            int x, y;
            cin>>x>>y;
            x--; y--;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        xor_val.assign(n, 0);

        dfs_xor(0);

        // if xor of root is zero, then answer would be "YES"
        if(!xor_val[0])
        {
            cout<<"YES\n";
            continue;
        }

        if(k == 1)
        {
            cout<<"NO\n";
            continue;
        }

        pos = 0;
        
        
        dp.assign(n, 0);
        dfs(0);

        if(pos)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }

    return 0;
}   
