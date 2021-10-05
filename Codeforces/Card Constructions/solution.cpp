#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
To construct a pyramid of height 'h' we need,
/\ = h + (h-1) + (h-2) + ... 2 + 1 = h*(h+1)/2
_ = (h-1) + (h-2) + ... 2 + 1 = h*(h-1)/2
Total cards required for h height = 2*(/\) + (_) = h*(3*h+1)/2

We will use a recursive approach to find the total number of pyramids 
that can be formed with given number of cards.

Also, provided with the number of cards - 'n', we will use binary search
to find the optimal height
*/
int max_height(ll n){
    if (n<2) return 0;
    // pyramid can only be constructed with atleast 2 cards
    ll low=0, high=n, mid, x, h=0;
    while (low<=high){
        mid = (low+high)/2;
        x = mid*(3*mid+1)/2;
        // finding the number of cards required to construct a pyramid of height mid
        if (x<=n){
            h=mid;
            low=mid+1;
            // if the cards required to construct a pyramid of height 'mid' is less than
            // given number of cards, check for possible height greater than 'mid'
        } else {
            high=mid-1;
            // if the cards required to construct a pyramid of height 'mid' is more than
            // given number of cards, try a height lower than 'mid'
        }
    }
    return 1+max_height(n-h*(3*h+1)/2);
    // The same function is run on the remaining cards to determine the pyramid of max height
    // than can be constructed. This function will return the total number of pyramids that
    // can be constructed
}

int main(){

    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << max_height(n) << endl;
    }

    return 0;
}