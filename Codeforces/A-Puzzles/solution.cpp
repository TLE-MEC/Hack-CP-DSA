#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n,m; // n is number of students. m is number of puzzles in shop 
    cin>>n>>m;
    ll puzzle[m]; //array for puzzles
    for(ll i=0;i<m;i++) cin>>puzzle[i];
    sort(puzzle,puzzle+m);
    ll start =0,end=n-1;
    ll diff=0,minDiff = INT_MAX; // diff is for storing difference in every iteration and minDiff is the minimum difference among them which is also the output
    while(end<m){
        diff = puzzle[end] - puzzle[start];
        minDiff = min(minDiff,diff);
        start++;
        end++;
    } 
    cout<<minDiff;
return 0;
}