#include <bits/stdc++.h>
#define int         long long int 
using namespace std; 

// custom comparator to sort pairs in decreasing order of integer(pair.first) but increasing order of string(pair.second)
bool comp(pair<int,string> a,pair<int,string> b)
{
    if(a.first > b.first) return true;
    else if(a.first == b.first)
    {
        if(a.second < b.second) return true;
        else return false;
    }
    else return false;
}

signed main() 
{
    int n,t; cin>>n>>t;
    // store the given integer and strings in vector of pairs
    vector<pair<int,string>> v(n);
    for(int i=0;i<n;i++)
    {
        string s; cin>>s;
        int x; cin>>x;
        v[i] = {x,s};
    }
    // sort the vector using custom comparator to sort them in decreasing order of fan quotient but increasing order of name
    sort(v.begin(),v.end(),comp); 
    // finally print the name of first t fans 
    for(int i=0;i<t;i++) cout << v[i].second << "\n";
 
return 0;
}