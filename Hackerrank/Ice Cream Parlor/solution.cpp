#include <iostream>
using namespace std;

void iceCreamParlor(int m, int cost[], int n);

int main()
{
    int t, m, n; // t, m, n are he number of trips to the ice cream parlor, the amount of money they have pooled and the number of flavors offered at the time respectively.

    cin >> t;

    // Now we'll iterate this loop for each once for each trip.
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n;  // As we have different set of m and n for each trip, let's take values of m and n here.

        int cost[n];    // We are generating an array of size n because we need to store price of n ice-cream flavors.

        for (int j = 0; j < n; j++) // We are storing prices of n flavors.
        {
            cin >> cost[j];
        }

        // Next we need to check which two flavors will cost us exactly that much money we have with us.
        // A separate function is used for modularity.

        iceCreamParlor(m, cost, n);
        // Our answers will be printed by the above function and hence our job is done.
    }

    return 0;
}

void iceCreamParlor(int m, int cost[], int n)
{
    // In the first loop, we will iterate from 1st element to (n - 1)th element. 
    for (int i = 0; i < n - 1; i++)
    {
        // In this loop, we will iterate from 2nd element to nth element.
        // If you observe carefully, in this way we'll manage to check all possible pair of elements in cost array.

        for (int j = i + 1; j < n; j++)
        {
            // If cost[i] + cost[j] == m then it means that (i + 1)th and (j + 1)th
            //  flavors can be purchased together (As i and j starts from zero,
            //  position of elements will be index + 1.)

            if (cost[i] + cost[j] == m)
            {
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
}
