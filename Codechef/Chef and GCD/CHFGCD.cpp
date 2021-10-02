#include <bits/stdc++.h>

using namespace std;

int main() 
{
	int t, n, ans;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int arr[n], count=0;
		map <int, int> mp;
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
			if(mp[arr[i]]!=arr[i]-1)
			{
				mp[arr[i]]++;
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}