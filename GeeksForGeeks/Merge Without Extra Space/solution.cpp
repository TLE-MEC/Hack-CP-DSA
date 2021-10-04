#include <bits/stdc++.h>
using namespace std;

/*
    Author : Sachin19k
*/

int main()
{
    int m,n;

    // input as length of array 1
    cout<<"Enter the length of array 1 : ";
    cin>>m;

    // input as length of array 2
    cout<<"\nEnter the length of array 2 : ";
    cin>>n;

    int arr1[m],arr2[n];

    // array 1
    cout<<"\nEnter the values of array 1 \n";
    for(int i=0;i<m;i++)
    {
        cin>>arr1[i];
    }
    // array 2
    cout<<"\nEnter the values of array 2 \n";
    for(int i=0;i<n;i++)
    {
        cin>>arr2[i];
    }

    int i = 0, j = 0, k = m - 1;

    // Till when i less than equal to k or j is less tha m
    // while traversing the two sorted arrays parallelly, if we encounter the jth second array element is smaller than ith first array element, then jth element is to be included and replace some kth element in the first array
    while (i <= k && j < n) 
    {
        if (arr1[i] < arr2[j])
        {    
            i++;
        }
        else 
        {
            swap(arr2[j++], arr1[k--]);
        }
    }
    
    // sort both arr1 and arr2 
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);

    cout << "After Merging \nFirst Array: ";
    for (int i = 0; i < m; i++)
        cout << arr1[i] << " ";
    cout << "\nSecond Array: ";
    for (int i = 0; i < n; i++)
        cout << arr2[i] << " ";
    return 0;
}


/* 
OUTPUT :
Enter the length of array 1 : 6
Enter the length of array 2 : 4
Enter the values of array 1 
1
5
9
10
15
20
Enter the values of array 2 
2
3
8
13
After Merging 
First Array: 1 2 3 5 8 9 
Second Array: 10 13 15 20
*/ 