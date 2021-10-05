#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<int> v(n);
        for(ll i=0;i<n;i++) cin>>v[i];
        ll minEle=v[0];
        for(ll i=1;i<n;i++){
            if(v[i] < minEle) minEle = v[i]; //computing minimum element of an array
        }
        deque<int> a; //initialising a dequeue
        for(ll i=0;i<n;i++){
            if(i==0)
            a.push_back(v[i]);
            else{
                if(v[i]>a[0]){
                    a.push_back(v[i]);
                }
                else{
                    a.push_front(v[i]);
                }
            }
        }
        for(ll i=0;i<n;i++) cout<<a.at(i)<<" ";
        cout<<endl;
    } 
return 0;
}