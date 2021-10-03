//Find if Chef is on time to take his 2nd dose of vaccine
//It has been 'd' days since Chef took his 1st dose
//Chef should take his 2nd dose no less than 'l' days after 1st dose
//Chef should take his 2nd does no more than 'r' days after 1st does

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;		//Variable for test cases	
	while(t--)        
	{
	    int d,l,r;
	    cin>>d>>l>>r;
	    if(d<l)				//Case where Chef is too early
	        cout<<"Too Early\n";
	    else if(d>r)			//Case where Chef is too late
	        cout<<"Too Late\n";
	    else				//Case where Chef is on time
	        cout<<"Take second dose now\n"; 
		
			
	}
}	