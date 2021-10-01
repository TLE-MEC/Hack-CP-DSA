#include<iostream>
#include<string>

using namespace std;

/* Brute force approach as per the question demand */

int main(){
    string s;
    cin>>s; // input string
    int n=s.length(); // checking string's length
    int count=0;      //Inititalized Counter 
    for(int i=0;i<n;i++){
        if(s[i]=='S'){
            if((i+1)%3==2){
                count++;
            }                           // Respective operations perfromed
        }
        else if(s[i]=='O'){
            if((i+1)%3!=2){
                count++;
            }                
        }
        else{
            count++;
        }
    }
    cout<<count;          // Print the solution
}
