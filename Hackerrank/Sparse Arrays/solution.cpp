#include<iostream>
#include<string>

using namespace std;

/* Question demands a brute force solution to the given problem */

int main(){
    int n;
    cin>>n; //input size
    string a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];            //input strings
    }
    int m;
    cin>>m;
    string b[m];
    for(int i=0;i<m;i++){
        cin>>b[i];          //input 2nd string
    }
    int c[m]={0};     //initialize counter array
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[i]==a[j]){
                c[i]++;             //calcukating number of occurences
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<c[i]<<endl;     //printing the result
    }
    
}
