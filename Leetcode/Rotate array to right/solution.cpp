#include<bits/stdc++.h>
using namespace std;

// A driver function to reverse an array/vector from index x to index y using swap(x,y)
void reverse(vector<int>& nums, long long int x, long long int y) {
	for (long long int i = x, j = y; i < j; i++, j--) {    //increment i and decrement j for each iteration
		swap(nums[i], nums[j]);
	}
}

// driver code to rotate vector to right by k=3
int main() {
	vector<int>nums{1, 2, 3, 4, 5, 6, 7};
	int k = 3;			//nums = [1,2,3,4,5,6,7], k = 3 (example testcase)
	int n = nums.size();
	k = k % n;
	reverse(nums, n - k, n - 1);   //reverse array from n-k to n-1 index
	reverse(nums, 0, n - k - 1);   //reverse remaining elements from 0 to n-k-1 indices
	reverse(nums, 0, n - 1);       //finally reverse whole array from 0 to n-1 indices

	for (int i = 0; i < n; ++i)    // print whole array/vector
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}
// OUTPUT: 5 6 7 1 2 3 4
