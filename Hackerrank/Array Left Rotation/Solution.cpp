#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, d; cin >> N >> d;
    vector<int> v(N);
    for (size_t i = 0; i < v.size(); ++i) {
        cin >> v[i];
    }
    d = d % N;
    for (int i = d; i < N; ++i)
        cout << v[i] << ' ';
    for (int i = 0; i < d; ++i)
        cout << v[i] << ' ';
    return 0;
}