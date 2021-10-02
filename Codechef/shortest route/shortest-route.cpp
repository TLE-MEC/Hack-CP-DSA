/*

https://www.codechef.com/JUNE21C/problems/SHROUTE

*/


#include <bits/stdc++.h>
using namespace std;
#define maxn 3E5+5
void solve(){
    int n,m; 
    cin>>n>>m;
    int a[n];
    int b[m];
    int i,j;
    for (i=0;i<n;i++){
        cin>>a[i];
    }
    for(i=0;i<m;i++){
        cin>>b[i];
    }
    int maxi=maxn;
    int temp[n];
    int low=-1,high=-1;
    for(i=0;i<n;i++){
       if(i==0){
        temp[i]=0;
       }
       else if(a[i]!=0){
        temp[i]=0;
       }
       else{
        temp[i]=maxi;   
       } 
   }
   for(i=0;i<n;i++){
       if(a[i]==1){
           high=i;
       }
       if(high!=-1){
           if(a[i]==0){
            temp[i]=min(temp[i],i-high);
           }
       }
   }
    for(i=n-1;i>=0;i--){
        if(a[i]==2){
            low=i;  
        }
        if(low!=-1){
            if(a[i]==0){ 
                temp[i] =min(temp[i],low-i);
            }
        }
    }
    for(i=0;i<m;i++){
        j=b[i]-1;
        if(temp[j]!=maxi){
            cout<<temp[j]<<" ";
        }
        else{
            cout<<-1<<" ";
        }
    }
   cout<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
