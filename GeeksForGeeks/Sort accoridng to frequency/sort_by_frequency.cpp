//sort an array according to their frequency
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//function to sort elements according to frequency
//this function is storing elements in decreasing order of their frequency
void getpos(vector<pair<int, int>> &temp, int entry, int frequency)
{
    int i;
    //looking for pos at which new element should be inserted
    for (i = 0; i < temp.size(); i++)
    {
        //we will insert the current element acc, to its frequency
        if (frequency >= temp.at(i).second)
        {
            if (frequency > temp.at(i).second || temp[i].first > entry)
            {
                temp.insert(temp.begin() + i, make_pair(entry, frequency));
                return;
            }
        }
    }
    //if temp vector is empty or there is no element having lower frequency
    //than current element we just insert at end
    if (temp.size() == 0 || i >= temp.size())
    {
        temp.push_back(make_pair(entry, frequency));
    }
}
vector<pair<int, int>> solve(int *arr, int size)
{
    unordered_map<int, int> map;
    //storing frequency in map
    for (int i = 0; i < size; i++)
    {
        map[arr[i]]++;
    }
    //vector pair to store sorted element and its frequency
    vector<pair<int, int>> temp;
    //traversing through map
    for (auto i : map)
    {
        getpos(temp, i.first, i.second);
    }
    return temp;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        vector<pair<int, int>> ans = solve(arr, size);
        for (int i = 0; i < ans.size(); i++)
        {
            while (ans[i].second--)
            {
                cout << ans[i].first << " ";
            }
        }
        cout<<endl;
    }
}