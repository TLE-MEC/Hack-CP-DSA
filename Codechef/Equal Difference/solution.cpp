// This is the C++ code for the CodeChef problem Equal Difference.
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void cal_equal_diff()
{
    int num;
    // The first line of each test case contains a number taken as input
    cin >> num;
    int great = 0, k;
    map<ll, int> p;
    // Run a loop for the value of k from 0 till num
    for (k = 0; k < num; k++)
    {
        // The second line of each test case contains num space-separated integers
        ll j;
        cin >> j;
        p[j]++;
        great = max(great, p[j]);
    }

    int result = 0;
    // If the value of num is less than 2 and further that of great equals 1
    if (num > 2)
    {
        if (great == 1)
        {
            // Store num-2 in result
            result = num - 2;
        }
        // Otherwise store num-great in result
        else
        {
            result = num - great;
        }
    }
    // Display the value of result as output
    printf("%d\n", result);
}
// Driver Code
int main()
{
    // Take the number of test cases as input
    int cases;
    cin >> cases;
    // Going over each test case
    while (cases--)
    {
        cal_equal_diff();
    }
    return 0;
}
/*
Sample Input:
3
2
1 2
5
2 5 1 2 2
4
1 2 1 2
Sample Output:
0
2
2
*/