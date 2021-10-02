#include <bits/stdc++.h>
#define int long long
using namespace std;

int binary(int arr[], int n, int key)
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

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int nextArr[n - 1];
        for (int i = 0; i < n - 1; i++)
            cin >> nextArr[i];

        sort(arr, arr + n);
        sort(nextArr, nextArr + n - 1);

        if (n == 2)
        {
            if (nextArr[n - 2] - arr[n - 1] > 0)
                cout << nextArr[n - 2] - arr[n - 1] << '\n';
            else
                cout << nextArr[n - 2] - arr[n - 2] << '\n';
            continue;
        }

        int possible = nextArr[n - 2] - arr[n - 1];

        if (possible <= 0)
        {
            cout << nextArr[n - 2] - arr[n - 2] << '\n';
            continue;
        }

        int copyArr[n - 1];
        for (int i = 0; i < n - 1; i++)
            copyArr[i] = nextArr[i] - possible;

        int flag = 1;

        for (int i = 0; i < n - 1; i++)
        {
            int pos = binary(arr, n, copyArr[i]);
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