#include<bits/stdc++.h>
using namespace std;

void solve()
{
   long long int n, g, b, atleast_days, total_days;

   cin >> n >> g >> b;
   total_days = n; // Minimum total_days required to pave the whole road 

   atleast_days = (n + 1) / 2; // Minimum number of good days required 

   total_days = (atleast_days / g) * (g + b); // Total days required to get minimum number of good days

   if (atleast_days % g) 
      total_days += atleast_days % g;

   else if (atleast_days % g == 0)
      total_days -= b; // since Good days come before bad days so when it is exactlly divisible we won't need to add next bad days
   
   // Example (for why we are subtracting b when atleast_days % g == 0) : 
   // 8 1 2
   // G BB G BB G BB G (road already paved no need for more) see when atleast_days % g so we won't need extra b
   
   // atleast_days = (8 + 1) / 2 = 9 / 2 = 4

   // total_days = 4 * (1 + 2) = 12
   // total_days = 12 - 2 = 10 

   total_days = max(n, total_days); // doing for cases when g > atleast_days, otherwise we would get total_days = 0 (before if as g > atleast_days)

   cout << total_days << "\n";
}

//============================== main ====================================================

int main()
{
   long long int t;

   t = 1;
   cin >> t;

   while (t--)
   {
      solve();
   }
}

// ============================== End =====================================================