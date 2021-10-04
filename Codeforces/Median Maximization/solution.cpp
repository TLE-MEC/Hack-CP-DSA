#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define ll              long long int
#define pb              push_back
#define mp              make_pair

void fastInput() {
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

void solve() {

   int n , s;
   cin >> n >> s;

    // finding the numbers which can be zero 
    // (all numbers will be zero befor the median element) 
   int zeroNums = ceil(n / 2.0) ;
   // the non zero numbers 
   int NonZeroNums = n - (zeroNums - 1);

    // handling corner case
   if (n == 1) {
      cout << s << endl;
      return;
   }

   int answer_ = 0;
   
   // if we cant place any Nonzero 
   // answer will be simple s/n 
   if (NonZeroNums == 0) {
      answer_ = s / n;
   } else if (NonZeroNums != 0) {
      answer_ = s / NonZeroNums;
   }
   cout << answer_ << endl;

   return;
}


int main() {

   fastInput();

   int t = 1;
   cin >> t;
   while (t--) {
      solve();
   }

   return 0;
}