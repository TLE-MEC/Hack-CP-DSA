#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *a, int n)
{
    unordered_map<int, int> m;     //creation of hashmap
    pair<int, int> ans = {0, 0};   //storing of the start of the sequence and its length (final)
    pair<int, int> temp = {0, 0};  //storing of the start of the sequence and its length per iteration
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;                 //inserting array's data into hashmap
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[a[i] - 1] == 0)     //checking if a[i] -1 exists or not 
        {
            j = 0;                       
            while (m[a[i] + j] > 0)
            {
                ++j;
            }
            temp.first = a[i];

            temp.second = j;
        }
        else
        {
            continue;
        }
        if (ans.second < temp.second)  //comparision of final answer with the current iteration,since we are looking for the longest subsequence
        { 
            ans.first = temp.first;
            ans.second = temp.second;
            temp = {0, 0};
        }
    }
    vector<int> output;                 //saving of final answer in a vector to return it
    output.push_back(ans.first);       
    if (ans.second == 1)                //ans.second=1 means only 1 value in the subsequence
    {
        return output;
    }
    output.push_back(ans.first + ans.second - 1);      
    return output;        //Return
}
//MAIN
int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1)
    {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}