#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>& nums, long long int x, long long int y) {
	for (long long int i = x, j = y; i < j; i++, j--) {
		swap(nums[i], nums[j]);
	}
}

// driver code to rotate vector to right by k=3
int main() {
	vector<int>nums{1, 2, 3, 4, 5, 6, 7};
	int k = 3;			//nums = [1,2,3,4,5,6,7], k = 3 (example testcase)
	int n = nums.size();
	k = k % n;
	reverse(nums, n - k, n - 1);
	reverse(nums, 0, n - k - 1);
	reverse(nums, 0, n - 1);

	for (int i = 0; i < n; ++i)
	{
		cout << nums[i] << " ";
	}
	cout << endl;
	return 0;
}
// OUTPUT: 5 6 7 1 2 3 4