#include <bits/stdc++.h>
using namespace std;
//Function declaration
int firstOccurence(int arr[], int n, int x);
int lastOccurrence(int arr[], int n, int x);

// Brute Force solution
int numberOfOccurrenceBF(int arr[], int n, int x)
{
    //This is brute force solution,where we iterate through all the elements in the array and check whether
    //it is equal to the given element,if yes we increment the count variable.
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            count++;
    }
    return count;
    //This algorithm takes O(n) time,since we are iterating through every element in the array.
    //O(1) Auxiliary space.
}

//Efficient solution - Func 1
int numberOfOccurrenceEfficient(int arr[], int n, int x)
{
    //Here we find first and last occurrence of a number in a sorted array using binary search.
    int first = firstOccurence(arr, n, x);
    if (first == -1)
        return 0;
    else
    {
        return lastOccurrence(arr, n, x) - first + 1;
    }
    //Time complexity - O(logn)
    //Auxiliary space - O(1) 
}

//Efficient solution - Func 2
int firstOccurence(int arr[], int n, int x)
{
    //First occurrence of a number using binary search algorithm
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] > x)
            h = mid - 1;
        else if (arr[mid] < x)
            l = mid + 1;
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
            {
                //This condition identifies whether number is at zeroth position or the number is occurring for the first time in the array.
                return mid;
            }
            else
            {
                //If number is not occurring for the first time we go left side of it using binary search.
                h = mid - 1;
            }
        }
    }
    return -1;
}

//Efficient solution - Func 3
int lastOccurrence(int arr[], int n, int x)
{
    //Last occurrence of a number using binary search algorithm
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] > x)
            h = mid - 1;
        else if (arr[mid] < x)
            l = mid + 1;
        else
        {
            if (mid == n - 1 || arr[mid + 1] != arr[mid])
            {
                //This condition identifies whether number is at last position or the number's occurrence ends here in the array.
                return mid;
            }
            else
            {
                //If number is not occurring for the last time we go right side of it using binary search.
                l = mid + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 2, 3};

    cout << numberOfOccurrenceBF(arr, 7, 2) << endl;
    cout << numberOfOccurrenceEfficient(arr, 7, 2) << endl;
    return 0;
}