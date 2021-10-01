#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;	//taking input of number of test cases.
	while (t--) //running the loop t number of times.
	{
		int x, y, z;
		cin >> x >> y >> z; //taking the input of x(number of present points),y(number of points to qualify) and z(number of matches left)
		if (z * 2 + x >= y)	//checking if the maximum points that rcb can earn is greater than qualifying point.
			cout << "YES" << endl;	//printing "YES " if condition statisfied.
		else
			cout << "NO" << endl;	//printing "NO" if condition not statisfied.
	}
	return 0;
}