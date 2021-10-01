#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <stack> 
#include <unordered_map>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const int mod=1e9+7;
#define rep(i,a,b) for (int i = a; i < b; i++)
#define  vec vector<ll>
void solve(){
 priority_queue<pair<int, int> > q;
    int n;
    cin >> n;
    for (int i = 1; i <=n; i++) {
        int x;
        cin >> x;
       q.push(make_pair(x,i));
    }
    vector<pair<int,int> >v;
    int cnt1,cnt2,x1,x2;
    while (q.size() >= 2) {
        auto it = q.top();
         cnt1=it.first;
         x1=it.second;
        q.pop();
          it = q.top();
         cnt2=it.first;
          x2=it.second;
        q.pop();
        if(cnt1>0 && cnt2>0){
            cnt1--;
        cnt2--;
          v.push_back(make_pair(x1,x2));
        }
        if (cnt1) {
            q.push(make_pair(cnt1,x1));
        }
        if (cnt2) {
            q.push(make_pair(cnt2,x2));
        }
    }
    cout<<v.size()<<endl;
    for(auto it:v){
        cout<<it.first<<" "<<it.second<<endl;
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif


    int t=1;
    cin>>t;
    while(t--){
     solve();
    }
    return 0;
}
