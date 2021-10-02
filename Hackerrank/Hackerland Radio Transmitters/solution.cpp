#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec;
//declaring as global variable so that we don't have to pass it in the function call (as it will create a new copy leading to increase in space)
int check(int dist)
{
    int count = 0, index = 0, pos;
    while (index < n)
    {
        count++; //stores the number of transmitters required
        pos = vec[index] + dist;
        //this loop counts the number of buildings affected on the left side of the transmitter
        while (index < n && vec[index] <= pos)
            index++;
        //when the previous loop breaks the index is one ahead of the range of transmitter. Hence we need to decrease the index by one
        index--;
        pos = vec[index] + dist;
        //this loop counts the number of buildings affected on the right side of the transmitter
        while (index < n && vec[index] <= pos)
            index++;
    }
    return count;
}
int main()
{
    int k;
    cin >> n >> k;
    vec.resize(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    sort(vec.begin(), vec.end());
    //sorting leads to O(n) time complexity
    cout << check(k);
}
