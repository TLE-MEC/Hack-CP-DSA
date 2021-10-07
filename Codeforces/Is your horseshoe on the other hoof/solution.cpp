//228A - Is your horseshoe on the other hoof?
// Code by :- Rishav Singh Solanki 


#include <iostream>
#include <algorithm>
using namespace std;
int arr[5], e = 3;
int main() {
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];	//Taking input from users
    }
    sort(arr, arr + 4);  // Sorting the array
    for (int i = 0; i < 3; i++) {
        if (arr[i] != arr[i + 1]) {	//Checking for same numbers
            e--;
        }
    }
    cout << e;
}