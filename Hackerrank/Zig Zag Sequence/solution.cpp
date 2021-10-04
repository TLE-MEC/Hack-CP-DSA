#include <bits/stdc++.h>
using namespace std;

void findZigZagSequence(vector < int > a, int n){
    
    // sorting the vector
    sort(a.begin(), a.end());
    
    // finding mid and swaping it with last element
    int mid = (n - 1)/2;
    swap(a[mid], a[n-1]);

    // moving start index forward and end index backwards
    int st = mid + 1;
    int ed = n - 2;
    while(st <= ed){
        swap(a[st], a[ed]);
        st = st + 1;
        ed = ed - 1;
    }
    
    // priting the vector
    for(int i = 0; i < n; i++){
        if(i > 0) cout << " ";
        cout << a[i];
    }
    cout << endl;
}

int main() {
    int n, x;
    int test_cases;
    cin >> test_cases;
    // driver code
    for(int cs = 1; cs <= test_cases; cs++){
        cin >> n;
        vector < int > a;
        for(int i = 0; i < n; i++){
            cin >> x;
            a.push_back(x);
        }
        findZigZagSequence(a, n);
    }
}



