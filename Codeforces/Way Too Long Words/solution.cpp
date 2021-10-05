#include<bits/stdc++.h>
using namespace std;
void solve(){
    /*if string size is greater than 10, we will print first character,
    then (length of string -2) which is the remaining characters in between the first and 
    last element of the string, and then we print the last character of the string..otherwise if length is 
    less than or equal to 10,then we simply print the string*/
      string s;
      cin>>s;
      int l=s.size();
     if(l>10) cout<<s.at(0)<<l-2<<s.at(l-1); else cout<<s;
     cout<<endl;
}
int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int t;
    cin>>t;
    while(t--){
      solve();  
}}
