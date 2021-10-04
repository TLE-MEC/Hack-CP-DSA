	#include <bits/stdc++.h>
	#include <iostream>
	#include <cmath>
	using namespace std;
	 
	int main()
	{
	    int i,j,n=0;
	    for(i=1;i<=5;i++)  //loop to start with row
	    {
	        for(j=1;j<=5;j++) //loop to start with column
	        {
	            cin>>n;        //storing value of each cell
	            if(n==1)       //searching for 1 in a cell
	            {
	            cout<<abs(i-3)+abs(j-3)<<endl;  //min number of moves to bring 1 at centre
	            }
	        }
	    }
	}
