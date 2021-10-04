#include<bits/stdc++.h>
using namespace std;
void solve(){
        int n;
        cin>>n;
        int a[n];
        int loc=0;
        for(int i=0;i<n;i++){
            cin>>a[i]; 
            if(a[i]==0) loc=i;
            }
        if(a[n-1]==0){ //it means that mocha can simply follow the continuous path from 1 to n and then go to (n+1)th village from nth village , as a[n-1] is 0.
             for(int i=1;i<=n+1;i++){
                 cout<<i<<" ";}
                 cout<<endl;
                 return;}
        if(a[0]==1){//here mocha firstly goes to (n+1)th village and from there , goes to 1st village and then follows the normal sequence till n.
            cout<<n+1<<" ";
             for(int i=1;i<=n;i++){
                 cout<<i<<" ";}
                 cout<<endl;
                 return;}
        
        if(a[n-1]!=0){  /*here firstly mocha travells in a normal sequence till it encounters a village with zero index ; then mocha takes a jump 
        from the village having a zero index to the (n+1)th village and
         comes back to the next village after that zero indexed village and travels till nth village.*/  
        for(int i=1;i<=loc+1;i++){
            cout<<i<<" ";
        }
        cout<<n+1<<" ";
        for(int i=loc+2;i<=n;i++){
            cout<<i<<" ";
        } }
        cout<<endl;
}
int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    while(t--){
      solve();  
}
}