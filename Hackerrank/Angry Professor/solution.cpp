#include<bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    int x;
    int N, k, sum;
    for (int i = 0; i < T; i++) {
        sum = 0;
        cin >> N >> k;
        for(int i = 0; i < N; i++) {
            cin >> x;
            // if negative then add to sum
            if (x <= 0) {
                sum++;
            }
        }
        // if sum<k the class gets cancelled
        if (sum < k) {
            cout << "YES" << endl;
        } 
        // else class has to be attended
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}