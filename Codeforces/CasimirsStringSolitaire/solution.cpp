
/*
    If count of A + count of c is equals to the count B, this is the only case in which we can
    erase string completely.
*/
#include<bits/stdc++.h>

using namespace std;
#define int long long


signed  main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t ;
    cin >> t;


    while (t--) {
        string s;
        cin >> s;
        int a = 0, b = 0, c = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'A') {
                a++;
            }
            else if (s[i] == 'B') {
                b++;
            }
            else c++;
        }

        if (a + c == b) {
            cout << "YES";
        }
        else cout << "NO";
        cout << endl;
    }


    return 0;

}