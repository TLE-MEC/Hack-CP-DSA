#include <bits/stdc++.h>
#define int long long
using namespace std;

int binary(int arr[], int n, int key) //code for binary search algorithm
{
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

int32_t main()
{

    int t;  //taking input for number of test cases
    cin >> t; 

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n]; //creating an array for input of array A
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int nextArr[n - 1]; //creating an array for input of array B
        for (int i = 0; i < n - 1; i++)
            cin >> nextArr[i];

        sort(arr, arr + n); 
        sort(nextArr, nextArr + n - 1); // sorted both the arrays in ascending order

        if (n == 2) //analying the corner case if n is equal to 2
        {
            if (nextArr[n - 2] - arr[n - 1] > 0)
                cout << nextArr[n - 2] - arr[n - 1] << '\n';
            else
                cout << nextArr[n - 2] - arr[n - 2] << '\n';
            continue;
        }

        int possible = nextArr[n - 2] - arr[n - 1]; //this represents difference between biggest numbers in both arrays

        if (possible <= 0)
        {
            cout << nextArr[n - 2] - arr[n - 2] << '\n';
            continue;
        }

        int copyArr[n - 1]; //making a new array with values as differnce of integres in array B and the integer possible
        for (int i = 0; i < n - 1; i++)
            copyArr[i] = nextArr[i] - possible;

        int flag = 1;

        for (int i = 0; i < n - 1; i++)
        {
            int pos = binary(arr, n, copyArr[i]); //using binary search to find out whether the element exists in the array copy or not
            if (pos == -1)
            {
                flag = 0;
                cout << nextArr[n - 2] - arr[n - 2] << '\n'; 
                break;
            }
        }

        if (flag)
            cout << possible << '\n'; 
    }
}