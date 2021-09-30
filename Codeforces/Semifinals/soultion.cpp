//after reading the problem you will find out that there are two main important cases
//1-if k=0 in this case we should choose n biggest elements from two sorted lists
//2-if k=n/2 then we just mark first n/2 people in each list

#include<bits/stdc++.h> 
using namespace std;
int n, i, x, y, a[100100], b[100100];//creating the variables needed to solve this problem

//n -> number of elements
//i -> our counter
//x -> our chosen number of elements in a
//y -> our chosen number of elements in b
//a is the first list

//b is the second list
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);	//making input output operation as fast as possible
	cin >> n;	//taking input "the number of elements in each list"
	for (i = 0; i < n; ++i) cin >> a[i] >> b[i], ++(a[x] < b[y] ? x : y);//iterate n times to take two inputs a and b and if (a>b) then we increase a else we increase b
	for (i = 0; i < n; ++i) cout << (i < max(x, n / 2) ? '1' : '0'); cout << endl;//iterate n times and printing zero or one as output which means the number is selected or not
	for (i = 0; i < n; ++i) cout << (i < max(y, n / 2) ? '1' : '0'); cout << endl;//the same as above but with b list
	return 0;
}
//Happy Coding :))
