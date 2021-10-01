#include <bits/stdc++.h>
using namespace std;
int sockMerchant(int n, vector<int> ar) {
    int arr[1000] = {0};
    for( int i =0 ; i < n ; i++)
    {
        arr[ar[i]]++;
    }
    int count = 0;
    for(int i=0; i<1000; i++)
    {
        if( arr[i] == 0)
            continue;
        else
            arr[i] = arr[i]/2;
    }
    for(int i=0; i<1000 ; i++)
    {
        count += arr[i];
    }
    return count;

}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr;
    cout << "Enter colors of socks with spaces: " << endl;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << sockMerchant(n,arr) << endl;
    return 0;
}