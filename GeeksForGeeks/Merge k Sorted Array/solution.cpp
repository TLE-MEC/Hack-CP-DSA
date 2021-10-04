// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> v;
        for (int i = 0; i < K; i++)
        {
            for (int j = 0; j < K; j++)
            {
                v.push_back(arr[i][j]);
            }
        }
        sort(v.begin(), v.end());
        return v;
        //code here
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(N, vector<int>(N, 0));
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }
        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends