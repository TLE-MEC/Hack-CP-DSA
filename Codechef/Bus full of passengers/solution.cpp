/*
Approach:
A vector is used to store the state each passenger of (whether they are inside the bus or not) and if we spot any inconsistencies a bool  variable named cons will be given the
value of false and the loop will be broken. if the value cons is false Inconsistent would be printed else consistent 
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,n,m,q,h,x; 
	char chr;
	
	cin>>t;
	for(int i=0;i<t;i++){
	bool cons = true;
	cin>>n>>m>>q;     // reading inputs
	vector<int> arr(n,0);
	int o=0;
	for(int j=0;j<q;j++){
	    
    cin>>chr>>x;
	    
	    if(chr=='+'&&arr[x-1]==0){arr[x-1]=1;o++;
	        if(o>m)
          {
            h=j+1;cons=false;break;             
          }   
	    }
	   else if(chr=='-'&&arr[x-1]==1){
       arr[x-1]==0;o--;
     }
    
	   else {
       cons=false; h=j+1; break;
     }
	   }
	  if(cons==false){ for(;h<q;h++)cin>>chr>>x; cout<<"Inconsistent\n";}
	  else cout<<"Consistent\n";
	  
	}
	return 0;
}
