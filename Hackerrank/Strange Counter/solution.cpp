#include <bits/stdc++.h>
using namespace std;
#define int long long // defining long long at start

/*
Here we just need to obtain a pattern. The starting time of every cycle is always 2 less than the value at the start of the cycle. So our only aim is to check in which cycle t lies
*/
int32_t main() //cannot use int main since int is defined as long long
{
    int t;
    cin >> t;
    int c = 1;
    int flag = 0;
    while (flag == 0)
    {
        if (t < 6 * c - 2)
            flag = 1;
        else
            c *= 2;
    }
    int temp = 3 * c - 2;
    int diff = t - temp; // position from the top of the cycle
    cout << 3 * c - diff; // actual value of t
    // Time complexity : O(log t) since in each case c is getting multiplied by 2
}