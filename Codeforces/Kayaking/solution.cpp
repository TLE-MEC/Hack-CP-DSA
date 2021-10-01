#include <bits/stdc++.h>

using namespace std;
#define sorta(v) sort((v).begin(),(v).end());
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); //speeds up the code
const int inf = 1e9 + 10;

void solve() {
    int n;
    cin >> n;
    n = n * 2; //as specified in the question
    vector<int> v(n); //vector of integers
    for (int i = 0; i < n; i++) cin >> v[i];
    sorta(v);  //stl function to sort tha vector in ascending order(defined above)
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) { //solution of O(n^2) time complexity
        for (int j = i + 1; j < n; j++) {
            vector<int> temp; 
            for (int k = 0; k < n; k++) {
                if (k != i && k != j)  //This condition because there are n-1 kayaks, hence we will have to leave a pair of people
                {
                    temp.push_back(v[k]);
                }
            }
            int ts = 0;
            for (int k = 0; k < n - 2; k += 2) {
                ts += (temp[k + 1] - temp[k]);
            }
            ans = min(ans, ts); //finding the minimum
        }
    }
    cout << ans << '\n';
}

int main() {
    faster
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
