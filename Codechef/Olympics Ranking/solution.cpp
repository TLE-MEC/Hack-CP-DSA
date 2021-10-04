// This is the C++ code for the CodeChef problem Olympics Ranking.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases, first_Country, second_Country, int_G1, int_G2, int_S1, int_S2, int_B1, int_B2;
    // Take the number of test cases as input
    cin >> cases;
    // Going over each test case
    while (cases--)
    {
        // The first and only line of each test case contains six space-separated integers G1, S1, B1, and G2, S2, B2
        cin >> int_G1 >> int_S1 >> int_B1 >> int_G2 >> int_S2 >> int_B2;
        // Store G1+S1+B1 in first_country
        first_Country = int_G1 + int_S1 + int_B1;
        // Store G2+S2+B2 in second_country
        second_Country = int_G2 + int_S2 + int_B2;
        // If the value of first_country is greater than second_country
        if (first_Country > second_Country)
        {
            // Display 1 as the output
            cout << "1" << endl;
        }
        // Otherwise, display 2 as the output
        else
        {
            cout << "2" << endl;
        }
    }
    return 0;
}
/*
Sample Input:
3
10 20 30 0 29 30
0 0 0 0 0 1
1 1 1 0 0 0
Sample Output:
1
2
1
*/