#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>

using namespace std;

/*
    The main idea of the solution is to solve each query according to
    the value of x[index] + y[index]

    Let root = (m)^1/2

    If x[index] + y[index] < root, we will store updates in a 2-d matrix and add values accordingly
    else we will update route array with values for updating path
*/

int root = 500;

int main()
{
    int n, m;
    cin>>n>>m;

    vi x(n), y(n);
    for(int i =0 ;i <n; i++) {cin>>x[i]>>y[i];} 

    int ans = 0;

    // 2-d matrix for storing values when x[index] + y[index] < root
    vvi dp(root, vi(root, 0));

    // route for storing values when x[index] + y[index] >= root
    vi route(m), timing(n);

    // Iterating over time
    for(int ti =0 ; ti < m; ti++)
    {
        // Calculating ans from both 2-d matrix and route array
        for(int i = 0; i < root; i++) ans += dp[i][ti%(i + 1)];
        ans += route[ti];

        int op, index;
        cin>>op>>index;
        index--;

        int val = x[index] + y[index];

        // Adding a train
        if(op == 1)
        {
            timing[index] = ti;
            
            if(val < root)
            {
                // Updating dp matrix
                dp[val - 1][timing[index]%val]--;
                dp[val - 1][(timing[index] + x[index])%val]++;
            } 
            else
            {
                // Updating route
                for(int i = timing[index] + x[index]; i < m; i += val) route[i]++;
                for(int i = timing[index] + val; i < m; i += val) route[i]--;
            }
        }
        else
        {
            if(val < root)
            {
                // Updating matrix 
                dp[val - 1][timing[index]%val]++;
                dp[val - 1][(timing[index] + x[index])%val]--;
            }
            else
            {
                // Updating route
                for(int i = timing[index] + x[index]; i < m; i += val) route[i]--;
                for(int i = timing[index] + val; i < m; i += val) route[i]++;
            }

            // If a removed train was counted in our answer subtract 1
            int cur_ti = (ti - timing[index])%val;
            if(cur_ti >= x[index]) ans--;
        }
    
        cout<<ans<<"\n";
    }

    return 0;
}   
