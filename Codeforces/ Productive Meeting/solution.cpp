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
bool cmp(const pair<int,int> &a,
                   const pair<int,int> &b)
{
       return a.second<b.second;
}
  const int dx[4] = { 1, 1, 0, 0};
      const int dy[4] = {-1, 1, -1, 1};
      bool isvalid(int x,int y,int n,int m){
    if(x>=0 && x<m && y>=0 && y<m) return true;

   return false;
}
void solve(){
 priority_queue<pair<int, int> > q;
 /* Using Priority _queue to take different pair and substract them*/
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
        // queue size should be greater than equal to 2
        // to use 2 make a pair
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
          // Each non zero pair is inserted
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
