// This is the C++ code for the CodeChef problem Shoe Fit.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases;
    int case1, case2, case3;
    // Take the number of test cases as input
    cin >> cases;
    // Going over each test case
    for (int i = 0; i < cases; i++)
    {
        // Take 3 integers as input indicating whether the shoe is left(represented using 0) or right(represented using 1)
        cin >> case1 >> case2 >> case3;
        // If all the shoes are left shoes, then display 0 as the output
        if (case1 == 0 && case2 == 0 && case3 == 0)
            cout << 0 << endl;
        // Otherwise, if all the shoes are right shoes, then display 0 as the output
        else if (case1 == 1 && case2 == 1 && case3 == 1)
            cout << 0 << endl;
        // Otherwise, display 1 as the output
        else
            cout << 1 << endl;
    }
    return 0;
}
/*
Example Input:
3
0 0 0
0 1 1
1 0 1

Example Output:
0
1
1
*/
