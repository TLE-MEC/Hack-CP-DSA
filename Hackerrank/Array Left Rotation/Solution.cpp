#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int N, d; // N = array , d = operation we have to perform
    cin >> N >> d; //taking input of n and d
    vector<int> v(N); // specifing that the vector has a size of N
    for (size_t i = 0; i < v.size(); ++i) 
    {
        cin >> v[i]; //taking input
    }
    d = d % N;
    for (int i = d; i < N; ++i)
        cout << v[i] << ' '; // printing the array output
    for (int i = 0; i < d; ++i) // for loop
        cout << v[i] << ' '; // printing the array output
    return 0;
}
