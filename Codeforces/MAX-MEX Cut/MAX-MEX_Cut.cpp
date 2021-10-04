#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
 /* Since we have to maximise the Mex and the greatest possible Mex out of 0 and 1 can be 2. So we'll 
 individually take all "0-1" pairs and get a Mex of 2 out of all of such pairs.
 One "0-1" pair = 2 added to the total Mex count.*/   
    ll nn;
    cin>>nn;
    string a,b;
    cin>>a>>b;
    ll l=a.size();
    for(ll i=0;i<l;i++){
        if(a[i]!=b[i]) //i.e.,one number is 0 and other one is 1.So replace such number with "-" sign.
        {a.replace(i,1,"-");b.replace(i,1,"-");}}
    for(ll i=0;i<l-1;i++){
        if(a[i]==b[i]){
        /*we separately count all the "0" followed by "1" or "1" followed by "0".
        They are consecutive in both strings and hence give a mex of 2.*/
            if(a[i]=='1' && a[i+1]=='0')
            {a.replace(i,1,"+");a.replace(i+1,1,"+");b.replace(i,1,"+");b.replace(i+1,1,"+");}
            else if(a[i]=='0' && a[i+1]=='1') 
            {a.replace(i,1,"+");a.replace(i+1,1,"+");b.replace(i,1,"+");b.replace(i+1,1,"+");}
        }} 
    ll combined=count(a.begin(),a.end(),'+');
    ll zero=count(a.begin(),a.end(),'0'); /* Now since all the remaining characters have been replaced by
   either "-" or "+" . So we are only left with "0" , which gives a mex  of "1".
   So we get a count of this.*/ 
    ll minus=count(a.begin(),a.end(),'-');
    cout<<combined+zero+(minus*2)<<endl;
}
int main(){
  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   ll tt;
   cin>>tt;
   while(tt--){
       solve();
   }
}