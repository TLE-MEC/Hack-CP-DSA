#include <bits/stdc++.h>
using namespace std;
int main() {                                     //time complexity - O(n) (worst case)
	int t;
	cin>>t;
	while(t--){
	    int n;
	    string s;
	    cin>>n>>s;
	    bool suspicion = false;        //tracks if the teacher should be suspicious or not
	    unordered_set <char> uset;     // STL data structure stores values with O(1) lookup and doesnt store repeat elements
	    
	    
	    uset.insert(s[0]);              //inserts first element to the set
	    for(int i = 1; i < s.length(); i++){
	        if(s[i] != s[i-1]){
	        if(uset.find(s[i]) == uset.end())    // element is not present in set
	        uset.insert(s[i]);                   //adding element to the set
	        
	        else{                                //element is found
	        suspicion = true;                    //Teacher will be suspicious
	        break;                               //breaks the loop
	        }
	    }
	    }
	    if(suspicion == false)
	    cout<<"YES"<<"\n";
	    else
	    cout<<"NO"<<"\n";
	}
	return 0;
}
