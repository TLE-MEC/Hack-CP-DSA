#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/*
Consider two separated case:-
1) When the maximum element is 1
2) When the maximum elenent is not 1

Case 1 is possible only when 1+1+1..n times is divisible by k
i.e. n is divisible by k

In case 2, let the max element be x.
It is only possible to contruct a series which is divisible by k (with max element x)
if x*n is greater than k
This is because x can be replaced by any number smaller number to adjust the sum such that
it becomes either equal or divisible by k

e.g n=5 k=3
Clearly, 3 is a possible candidate for maximum element
Let us check for 2, 2*5 = 20 > 3. Then 2 can also serve as the maximum element - {1,1,1,1,2}
Let us check for 1, 1*5 = 5 (not divisible by 3). So, 1 cannot be the max element

Our aim is to find a number x using binary search from 1 to k
*/

bool check(ll n, ll k, ll mid){
    // this function checks whether the number mid is a possible maximum element of series
    // i.e. if a series can be made with max element mid whose sum is divisible by k
    if (mid==1) return n%k==0;
    return mid*n >= k;
}

int main(){

    ll t, n, k;
    cin >> t; // test cases
    while (t--){
        cin >> n >> k;
        ll low=1, high=k, mid, ans=k;
        // k is always a possible maximum element of series
        // because sum of a series {k,k,k,...} is always divisible by k
        while (low<=high){
            mid = (low+high)/2; // calculating middle number
            if (check(n, k, mid)){
                ans = mid;
                high = mid-1;
                // if mid is a possible candidate
                // then perform the check on smaller numbers only
            } else {
                low = mid+1;
                // if mid is too small to be the max element
                // then perform the check on bigger numbers only
            }
        }
        cout << ans << endl;
    }

    return 0;
}