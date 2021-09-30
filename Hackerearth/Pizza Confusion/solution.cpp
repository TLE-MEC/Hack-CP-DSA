#include <bits/stdc++.h> 
#include<string.h>
using namespace std;
int main( )
{
    int n;//total number of the restaurants
	cin>>n;
	int arr[n];//array to store the points given to restaurants
	string name[n];//array to store the names of restaurants
	cin>>name[0] >>arr[0];//entering the first restaurant name and its point
	int max=arr[0];
	string x= name[0];
	for(int i=1;i<n;i++)
	{
		cin>>name[i] >>arr[i];
    /*if the points is greater than max then max will be assigned this new value and thus restaurant name will be changed*/
		if(arr[i]>max)
		{
			max=arr[i];
			x=name[i];
		}
    /*if the point is equal to max then lexicographically smallest name will be considered*/
		if(arr[i]==max)
		{
			if(x.compare(name[i])>0)
			x=name[i];
		}
	}
	cout<<x;
	
    return 0;
}
