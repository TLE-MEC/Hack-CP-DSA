#include<iostream>
#include<string>
#include<bits/stdc++.h>

using namespace std;

/* The main idea behind the solution is using hashing technique for all the 26 characters. */

int main(){
    string s;
    getline(cin,s); //Converging the input string
    transform(s.begin(), s.end(), s.begin(), ::tolower); // converting the complete string to lowercase
    int a[26]={0}; // Hashing array
    int n= s.length();
    for(int i=0;i<n;i++){ 		//traversing the complete string
        if(s[i]!=' '){
            a[s[i]-'a']++;		// incrementing the index of the letter once it is found
        }
    }
    int c=0;
    for(int i=0;i<26;i++){
        if(a[i]==0){
            c=1;			// in case any index is zero, turning the switch on
        }
    }
    if(c==0){
        cout<<"pangram"<<endl; 		// printing the result
    }
    else{
        cout<<"not pangram"<<endl;
    }
    
    
}