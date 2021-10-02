#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int testCases;
	cin>>testCases;
	while(testCases--)
	{   
        // according to the question, variables correspond to:
        // n -> n
        // shops -> s
        // people -> p
        //  price -> v
	    int n,shops,people,price;
	    cin>>n;
	    // profits contains profit for each item
	    int profits[n];
	    int i=0;
	    while(i<n)
	    {
	        cin>>shops>>people>>price;
	        
	        // we're doing shops+1 as chef opens profits "new" store, in-addition to existing shops
	        profits[i++]=(people/(shops+1))*price;
	    }
	    cout<<*max_element(profits,profits+n)<<endl;
	}
	return 0;
}