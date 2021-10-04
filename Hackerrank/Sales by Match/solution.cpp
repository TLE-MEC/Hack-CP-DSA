#include <bits/stdc++.h>
using namespace std;
// Function to calculate total number of pairs
int sockMerchant(int n, vector<int> ar) {
    int arr[1000] = {0}; // Making new array to count number of same colors of socks
    for( int i =0 ; i < n ; i++) // Loop to update each color of sock to 1
    {
        arr[ar[i]]++;
    }
    int count = 0;
    for(int i=0; i<1000; i++)
    {
        if( arr[i] == 0) // There is no socks of a color then leave it
            continue;
        else
            arr[i] = arr[i]/2; // If there is socks of same color make pair of it
    }
    for(int i=0; i<1000 ; i++) // To count total number of paired socks
    {
        count += arr[i];
    }
    return count;

}
int main()
{
    int n;  // To store array size
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr;//vector to store all inputed color of socks
    cout << "Enter colors of socks with spaces: " << endl;
    for(int i = 0; i < n; i++)// To take input all colors
        cin >> arr[i];
    cout << sockMerchant(n,arr) << endl;// calling function to give output of total paired socks
    return 0;
}
