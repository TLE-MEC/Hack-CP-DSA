#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); //speeds up the code
/*
prerequisite - circular permutations
learn from here: https://www.tutorialspoint.com/statistics/circular_permutation
 */
int factorial(int n)
{
    int ans = 1;
    for(int i = 1; i <= n; ++i) {
        ans  *= i;
    }
    return ans;
};
signed main(){
    FIO
    int n;
    cin>>n;
    int ans = factorial(n)/((n/2)*(n/2)*2); //calculated using circular permutations.. We devided by 2 to prevent counting ordered pairs 
    cout <<ans<<'\n';
    return 0;
}
