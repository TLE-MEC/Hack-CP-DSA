#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t; //taking input of number of test cases.
	while(t--)  //running testcases.
	{
	    int n,a,b,c;    
	    cin>>n>>a>>b>>c;    
        /*taking the input of n=number of needed dishes,a=number of fruits with chef,
        b=number of vegetables with chef,c=number of fishes with chef*/
	    if(b<n) 
        /*As we know from the question chef needs 1 vegetable for both the variety of dishes that he can make.
        So if number of vegetable is less than number of dishes to be made then total number of given dishes can not 
        be made hence we print "NO".*/
	        cout<<"NO"<<endl;
	    else    /*Now as the requirement of vegetable is fullfilled, we check if the chef has required number
        of fruits and fishes.As any one of them is required to make a dish we add both of them 
        to get the total number of dishes chef can make ,if its less than the needed number of 
        dishes we print "NO" otherwise we print "YES".*/
	    {
	        if((a+c)<n)
	            cout<<"NO"<<endl;
	        else
	            cout<<"YES"<<endl;
	    }
	}
	return 0;
}