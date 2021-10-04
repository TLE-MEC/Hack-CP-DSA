#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void solve()
{
    string s;
    cin>>s;
    int l=s.size();
    /*if string has all elements as "1" then Mex will be "0"
    if string has all elements as "0" then Mex will be "1" */
    if(count(s.begin(),s.end(),'1')==l) {cout<<"0"<<endl; return;}
    else  if(count(s.begin(),s.end(),'0')==l) {cout<<"1"<<endl; return;}
    else{
       int c1=0;
       for(int i=0;i<l-1;i++){
           if(s.at(i)!=s.at(i+1)) c1++; //storing how many times we can segregate strings
       }
       int p=min((count(s.begin(),s.end(),'0')),2); //in the WORST Case also , the minimum Mex can never ecxeed 2.
       if(c1==2 && s[0]=='1') {cout<<"1"<<endl; return;} 
       cout<<min(p,c1)<<endl;  
    } 
}
int main(){
  ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int tt;
   cin>>tt;
   while(tt--){
       solve();
   }
}