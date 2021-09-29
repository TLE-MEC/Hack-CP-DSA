#include <bits/stdc++.h>

using namespace std;

// Approach 1 - Brute force
// Time complexity: O(n^2), Space complexity: O(1)
bool twoSum_1(vector<int> arr, int target)
{
    for (int i = 0; i < arr.size(); i++)
        for (int j = i+1; j < arr.size(); j++)
            if (arr[i] + arr[j] == target)
                return true;

    return false;
}

// Approach 2 - Sort + Binary Search
// Time complexity: O(nlogn), Space complexity: O(1)
bool twoSum_2(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); i++)
    {
        int complement = target - arr[i];
        if (binary_search(arr.begin() + i + 1, arr.end(), complement))
            return true;
    }
    return false;
}

// Approach 3 - Sort + Two pointers
// Time complexity: O(nlogn), Space complexity: O(1)
bool twoSum_3(vector<int> arr, int target)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = arr.size() - 1;
    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
            return true;
        else if (sum < target)
            left++;
        else
            right--;
    }
    return false;
}

// Approach 4 - Hashing
// Time complexity: O(n), Space complexity: O(n)
bool twoSum_4(vector<int> arr, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        int complement = target - arr[i];
        if (mp.find(complement) != mp.end())
            return true;
        mp[arr[i]] = i;
    }
    return false;
}

int main()
{
    int n, k, inp;
    cin >> n >> k;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        arr.push_back(inp);
    }
    if (twoSum_4(arr, k))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}