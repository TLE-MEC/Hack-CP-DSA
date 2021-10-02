#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    
    int a,b;
    cin>>a>>b;
    
    string one[] = {" ", "one","two","three","four","five","six","seven","eight","nine"};
    
    for(int i=a;i<=b;i++){
        if(i<=9){
            cout<<one[i]<<endl;
        
        }
        else if (i%2==0){
            cout<<"even"<<endl;
        }
        else{
            cout<<"odd"<<endl;
        }
    }
    
    

    // Complete the code.
    return 0;
}