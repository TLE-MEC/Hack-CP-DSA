// Time complexity : O(n) where n is the number of strings in a given test case
// Space complexity : O(1)

#include <bits/stdc++.h>
using namespace std;


int main() {
  
	int t,n;                          // t is the number of test cases and n is the number of binarry strings in each testcase
	cin>>t;
	string s,ans="";                  // s stores each input string and ans stores the expected output
  
	for(int i=0;i<t;i++){
	   
    cin>>n;
	   
	    for(int j=0;j<n;j++){
        
	      cin>>s;
	      if(s[j]=='1')ans+='0';  // appends '0' to the ans string if the indice i of string s has a value of  '1'
	      else ans+='1';          // else appends '1' to ans
                                /* the logic is to get a completely differnt binary string by assigning the value of '1' to the ith indice of the ans variable if the ith indice
                                    of the ith string is '0' (and vice versa) */
	      }
    
	    cout<<ans<<"\n";
	  
    ans="";
	    
	}
  
	return 0;
}
