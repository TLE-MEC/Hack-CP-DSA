// This is the C++ code for the CodeChef problem Problem Difficulties.
#include <bits/stdc++.h>
#define pbk push_back
using namespace std;

int main()
{
    long long cases;
    long long k;
    // Take the number of test cases as input
    cin >> cases;
    while (cases--)
    {
        // Going over each test case
        unordered_map<long long, long long> pd;
        long long a[4];
        for (k = 0; k < 4; k++)
        {
            // The first and only line of each test case contains four space-separated integers A1, A2, A3, A4, denoting the difficulty level of four problems.
            cin >> a[k];
            pd[a[k]]++;
        }
        vector<long long> tmp;
        for (auto q : pd)
        {
            // push back q.second in the vector tmp
            tmp.pbk(q.second);
        }
        // sort tmp
        sort(tmp.begin(), tmp.end(), greater<>());
        // If the element at 0th index of tmp is greater than 3
        if (tmp[0] > 3)
        {
            // Display 0 as the output
            printf("0\n");
        }
        // Otherwise, if the element at 0th index of tmp is greater than 3
        else if (tmp[0] > 2)
        {
            // Display 1 as the output
            printf("1\n");
        }
        else
        {
            // Otherwise, display 0 as the output
            printf("2\n");
        }
    }
    return 0;
}
/*
Sample Input:
3
1 4 3 2
4 5 5 5
2 2 2 2
Sample Output:
2
1
0
*/