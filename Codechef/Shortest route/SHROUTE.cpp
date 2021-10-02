#include <bits/stdc++.h>
using namespace std;
const int maxm = 1000000000;
int main()
{
	int t, n, m, temp;
	cin >> t;
	while(t--)
	{
		map <int, int> mp;
		cin >> n >> m;
		int arr1[n], arr2[m];
		for(int i=1; i<=n; i++)
		{
			cin >> arr1[i];
			if(arr1[i] != 0)
				mp[i] = 0;
			else
				mp[i] = maxm;
		}
		mp[1] = 0;
		int p_one = -1;
		for(int i=1; i<=n; i++)
		{
			if(arr1[i]==1)
				p_one = i;
			if(p_one!=-1)
			{
				if(arr1[i]==0)
					mp[i] = min(mp[i], i-p_one);
			}
		}
		int p_two = -1;
		for(int i=n; i>=1; i--)
		{
			if(arr1[i]==2)
				p_two = i;
			if(p_two!=-1)
			{
				if(arr1[i]==0)
					mp[i] = min(mp[i], p_two-i);
			}
		}
		for(int i=0; i<m; i++)
		{
			cin >> temp;
			if(mp[temp]==maxm)
				arr2[i]=-1;
			else
				arr2[i] = mp[temp];
		}
		for(int i=0; i<m; i++)
			cout << arr2[i] << " ";
		cout << endl;
	}

	return 0;
}