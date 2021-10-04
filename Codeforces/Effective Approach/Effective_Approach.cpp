#include<bits/stdc++.h>
using namespace std;
void solve(){
     int n;cin>>n;
     map<int,int>m;
      map<int,int>l;
     long long int sumv=0,sump=0;
     for(int i=1;i<=n;i++){
         int x;cin>>x;
         m.insert({x,i}); //Vasya's Map having sequential Data
        l.insert({x,n-i+1}); //Petya's Map having Reverse Sequential Data
     }
     int k; cin>>k; //total k queries
     for(int j=1;j<=k;j++){
        int y;cin>>y;
        sumv+=m[y]; //Here the key is the number on the array and the value is the index according to Vasya
        sump+=l[y];//Here the key is the number on the array and the value is the index according to Petya
     }
     cout<<sumv<<" "<<sump;
}
int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    int t=1;
    //cin>>t;
    while(t--){
      solve();  
}}