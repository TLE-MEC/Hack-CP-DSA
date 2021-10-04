// A STL based C++ program to sort a nearly sorted array.
#include <bits/stdc++.h>
using namespace std;

// Given an array of size n, where every element
// is k away from its target position, sorts the
// array in O(n logk) time.
int sortK(int arr[], int n, int k)
{
	
	// Insert first k+1 items in a priority queue (or min
	// heap)
	//(A O(k) operation). We assume, k < n.
//if size of array = k i.e k away from its target position
//then
	int size;
	size=(n==k)?k:k+1;
	priority_queue<int, vector<int>, greater<int> > pq(arr, arr +size);

	// i is index for remaining elements in arr[] and index
	// is target index of for current minimum element in
	// Min Heap 'pq'.
	int index = 0;
	for (int i = k + 1; i < n; i++) {
		arr[index++] = pq.top();
		pq.pop();
		pq.push(arr[i]);
	}

	while (pq.empty() == false) {
		arr[index++] = pq.top();
		pq.pop();
	}
}

// A utility function to print array elements
void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

// Driver program to test above functions
int main()
{
	int k = 3;
	int arr[] = { 2, 6, 3, 12, 56, 8 };
	int n = sizeof(arr) / sizeof(arr[0]);
	sortK(arr, n, k);

	cout << "Following is sorted array" << endl;
	printArray(arr, n);

	return 0;
}