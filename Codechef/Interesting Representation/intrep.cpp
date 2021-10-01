/* September Lunchtime 2021- Division 3- Interesting Representation (INTREP)*/

#include <iostream>
using namespace std;
#define ll long long

int v[] = {3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73};

int main() {
	
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		ll n;
		cin >> n;
		if (n % 2 == 0) {
			ll a = 2 * n;
			ll b = n;
			cout << a << " " << b;
		} else {
			int j = 0;
			while (n % v[j] == 0)
				j++;
			ll a = n * v[j];
			ll b = n * (v[j] - 1);
			cout << a << " " << b;
		}
		cout << "\n";
	}
	return 0;
}