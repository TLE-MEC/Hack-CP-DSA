#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() 
{
	long t, i;
	long long a, b;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		string x1, x2, x3;
		for(i=63; i>=0; i--)
		{
			if(a&(long long)1<<i)
				x1 +='1';
			else
				x1 +='0';
		}
		for(i=63; i>=0; i--)
		{
			if(b&(long long)1<<i)
				x2 +='1';
			else
				x2 +='0';
		}
		for(i=0; i<64; i++)
		{
			if(x1[i]=='1' && x2[i]=='1')
				break;
		}
		while(x1[i]==x2[i])
		{
			x3 += x1[i];
			i++;
		}
		for(i; i<64; i++)
			x3 += '0';
		long long ans = 0;
		int s = x3.length();
		for(i = 0; i<s; i++)
		{
			if(x3[i]=='1')
				ans += (long long)1<<(s-i-1);
		}
		cout << ans << endl;
	}
	return 0;
}