#include<iostream>
#include<string>
#include<cmath>
using namespace std;

/* A pure brute force approach as directed by the question */

int main(){
    int t;
    cin>>t; // number of test cases
    while(t--){
    string s;
    cin>>s;
    int t=s.length();   //Checking the length using string in-built function
    int n= t-1;
    int a[n];
    int f=0;
    int b=0;
    if(n%2==0){
        f=1;        // Declaring Flag variable to check whether odd or even
    }
    for(int i=0;i<t-1;i++){
        a[i]=abs(s[i]-s[i+1]);     // Calculating absolute difference
    }
    if(f){
        int i=0,j=n-1;
        for(;i<n/2&&j>=n/2;i++,j--){
            if(a[i]!=a[j]){
                b++;
            }
        }
    }
    else{
        int i=0,j=n-1;
        for(;i<n/2&&j>n/2;i++,j--){
            if(a[i]!=a[j]){
                b++;
            }
        }       
    }
    if(b){
        cout<<"Not Funny"<<endl;
    }
    else {
    cout<<"Funny"<<endl; // printing result
    }
}
}
