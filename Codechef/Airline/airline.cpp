#include<iostream>
using namespace std;

//Creating a class Luggage containing all information about the luggage
class Luggage
{
    public:
    int A,B,C,D,E;
    int compare()
    {
      //All the possible conditions for which luggage is allowed and we return the function
        if(A+B<=D)
     	{
	    	if(C<=E)
		    {
			    cout<<"YES"<<endl;
    			return 0;
	    	}
    	}
	    if(B+C<=D)
    	{
	    	if(A<=E)
		    {
			    cout<<"YES"<<endl;
    			return 0;
	    	}
    	}
	    if(A+C<=D)
    	{
	    	if(B<=E)
		    {
			    cout<<"YES"<<endl;
    			return 0;
	    	}
    	}
	  //If any of the above conditions fails then luggage is not allowed and 0 is returned.
	    cout<<"NO"<<endl;
	    return 0;
    }
};

int main()
{
  //Getting total number of cases
    int x;
    cin>>x;
  //Array of object consisting of information about every case
    Luggage l[x];
    
    for(int i = 0; i < x; i++)
    {
        cin>>l[i].A>>l[i].B>>l[i].C>>l[i].D>>l[i].E;
    }
  
  //Calling the function for every case
    for(int i = 0;i<x;i++)
    {
        l[i].compare();
    }

    return 0;
}
