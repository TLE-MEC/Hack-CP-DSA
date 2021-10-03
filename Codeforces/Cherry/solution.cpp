#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;

    //taking number of test cases
    cin >> t;
    while (t--)
    {
        long long n;

        //taking the total number of integers
        cin >> n;
        long long arr[100000], a[100000];
        
        //taking input of n integers
        for (long long i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        //filling an array 'a' with product of two consecutive numbers of array 'arr'

        /*
        
        Explanation for this step:
        this is done in order to get a subarray of multiplied max's and min's of elements of array 'arr'

        */
        for (long long i = 0; i < n - 1; i++)
        {
            a[i] = arr[i] * arr[i + 1];
        }

        //using in-built function max_element to find max element of updated array 'a'
        cout << *max_element(a, a + n - 1) << endl;
    }
    return 0;
}
