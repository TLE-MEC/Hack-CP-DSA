#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int solver(int n, int arr[])
    {
        //If the value is in the look up table directly return the value, no need to compute
        if (arr[n] != -1)
            return arr[n];

        //Else compute using the recurrence relation given and store and return the result
        return arr[n] = solver(n - 1, arr) + solver(n - 2, arr) + solver(n - 3, arr);
    }

    int tribonacci(int n)
    {
        int arr[n + 1];
        //Populate arr lookup table initially with -1
        memset(arr, -1, sizeof(arr));
        //Set arr[0], arr[1], arr[2] to 1 as first three numbers are 0, 1, 1 respectively
        arr[0] = 0;
        if (n >= 1)
            arr[1] = 1;
        if (n >= 2)
            arr[2] = 1;
        return solver(n, arr);
    }
};

int main()
{
    int n = 25;
    Solution s1;
    cout << s1.tribonacci(n);
    return 0;
}