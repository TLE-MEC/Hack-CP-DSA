#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()

typedef vector<string> vs;
typedef long long  ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
const int mod = 1e9+7;
const int inf{INT_MAX};
const ll linf {LLONG_MAX};
template <typename T>
void debug(T a){cout << a << endl;}
template <typename I, typename T>
void debug(I i, T a){cout << i << ": " << a << endl;}

void solve(){

int n;
cin >> n;

vi nums(n);

rep(i,0,n){
    cin >> nums.at(i);
}
int a{0},b{0};
rep(i,0,n){

int x;
cin >> x;
    if(x == 1){
        ++a;
    }
    else{
        ++b;
    }
}

if(is_sorted(all(nums)) || (a > 0 && b > 0)){

cout << "YES\n";

return;

}
else{
    cout << "NO\n";
    return;
}




}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    #endif
    int t{0};
    cin >> t;

    while(t--){
     solve();
    }



return 0;
}