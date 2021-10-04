#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int t,n,i=0,j;
	char a[1000], p[]="NOT SURE";
	cin>>t; //inputting and looping test cases
	while(t--)
	    {
	        i=0;
	        strcpy(p,"NOT SURE"); //initially saving as not sure
	        cin>>n;
	        while(i<n)
	            {
	                i++;
	                cin>>a[i];
	                if(a[i]=='I') //if we see an indian nod, we can confirm he/she is indian
	                   strcpy(p,"INDIAN");
	                else if(a[i]=='Y') //if we see the yes nod, we can confirm he/she is not indian
	                    strcpy(p,"NOT INDIAN");;
	            }
	       cout<<p<<endl; //print the answer
	            
	    }
	return 0;
}
