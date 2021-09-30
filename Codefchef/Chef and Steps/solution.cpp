#include <iostream>
#include <string>

using namespace std;

int main() {
	// your code goes here
	int t, n, k, x, i;
	cin>>t;
	string s;
	while(t--)	
	{
	    s = "";
	    cin>>n>>k;	//Taking Input of n = No. of distances and k = Chef's step length
	    int x[n];
	    for(i=0;i<n;i++)
	    {
	        cin>>x[i];	//Taking Input distance of i'th path
	        if(x[i]%k==0)	//if the distance of i'th place is traversable then add 1 into the string s
	        s = s+"1";
	        else
	        s = s+"0";	//If the chef can not travel to i'th place then add 0 to the string 
	    }
	    cout<<s<<endl;	//finally print the pattern obtained for each testcase
	}
	return 0;
}
