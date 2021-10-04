#include <bits/stdc++.h>
#define int long long int
using namespace std;

/*
Formula for sum of first k element of arithmetic series whose first value is "a" and diffrence between two consecutive element is "d"
-> Sk=(k/2)(2∗a+(k−1)∗d)

Here d = 1 and sk = n
-> n=(k / 2) * (2 ∗ a + (k − 1))
-> n=(k ∗ a) + (k ∗ (k − 1)) / 2
-> n − (k ∗ (k − 1)) / 2 = k ∗ a
-> (n−k∗(k−1)/2) / k = a

As "a" is the first value n the sequence, It need to be integer value not double.

So, we will go over all possible value of k for given n and check if a is an integer or not.
*/

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for (int k = 1; (k * (k + 1)) / 2  <= n; k++) {
        int cur = n - ((k * (k - 1)) / 2);
        if (cur % k == 0){
            // "  n - ((k * (k - 1)) / 2)  " is divisible by "k", it means "a" is integer.
            ans++;
        }
    }
    cout << ans * 2 << '\n' ;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}

