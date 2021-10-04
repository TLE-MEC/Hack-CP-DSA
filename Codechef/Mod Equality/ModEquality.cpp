#include <bits/stdc++.h>
using namespace std;

/*
In the problem we are given an array A containing N non-negative integers

We can apply following operation any number of times
Choose any index i and replace Ai with Ai%M

M need not be same in every operation

Our objective is to minimize the operation and make every element equal

So our best option is to reduce every array element to smallest value present

Case 1:
Ex. Array=[1, 4, 5, 6]
We can obtain [1,1,1,1] in 3 operations
4 % 3 = 1
5 % 4 = 1
6 % 5 = 1
So ans for such cases is N - frequencyOf(smallest)

Case 2:
But there is one more case
Ex. Array=[5, 6, 9, 10]
Here we cannot convert 6 to 5 using modulo operation
In general if 2nd Smallest element is <= 2*smallest we cannot convert it to smallest
using module
So ans for such cases is N

*/

void solve()
{
    long long n, m = INT_MAX;
    cin >> n;

    // map is used to calculate frequency of elements in the given array
    map<long long, long long> x;

    // scanning array and calculating frequency
    for (long long i = 0; i < n; i++)
    {
        long long a;
        cin >> a;

        // m stores the minimum value present in array
        m = min(m, a);
        x[a]++;
    }

    // 2nd smallest element in the array
    auto itr = x.upper_bound(m);

    // if array contains more then 1 different values
    if (itr != x.end())
    {
        // 2nd smallest element is less then 2*smallest
        if (itr->first <= 2 * m)
        {
            cout << n << '\n';
            return;
        }
    }

    // when above condition are not satisfied
    cout << n - x[m] << '\n';
}

int main()
{
    long long T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}