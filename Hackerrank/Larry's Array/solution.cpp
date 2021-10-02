#include <bits/stdc++.h>
using namespace std;

/*
The main idea here is to find the number of elements which are smaller than the given element and occur after it in the given array. If the total count is even then the array can be fully sorted.
*/
int main()
{
    int q;
    cin >> q;
    while (q--) //Going through all test cases
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int count = 0;
        for (int i = 0; i < n - 1; i++) 
        //if i goes till n-1 then in next loop j becomes i+1 i.e. n which will give out of bounds error
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[i] > a[j])
                    count++; 
                    /*the count variable stores the number of elements which are smaller than a[i] and occur after it*/
            }
        }
        if (count % 2 == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    // Total time complexity : O(q*n^2)
}
