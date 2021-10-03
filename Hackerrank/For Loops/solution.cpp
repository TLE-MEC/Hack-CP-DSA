#include <iostream>  //header file
#include <cstdio>    //header file
using namespace std;

int main() {          //starting main function
    
    int a,b;          //declaring integer variables
    cin>>a>>b;        //taking input from user
    
    string one[] = {" ", "one","two","three","four","five","six","seven","eight","nine"};       //declaring a string 
    
    for(int i=a;i<=b;i++){                  //starting for loop
        if(i<=9){                           //if value of i is somewhere between a and b then it'll print the index value of that from string one[].
            cout<<one[i]<<endl;
        
        }
        else if (i%2==0){                   //if i is even i.e devisible by 2 then print "even".
            cout<<"even"<<endl;
        }
        else{
            cout<<"odd"<<endl;              //else print odd
        }
    }
    return 0;                               
}
