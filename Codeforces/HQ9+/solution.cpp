// here we have to print yes if any of H,Q,9 is present in the string input by user

#include<iostream>
using namespace std;

int main(void){
  // here we take input from user and store it in string
    string s;
    cin>>s;
    int flag=0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='H'|| s[i]=='Q' || s[i]=='9' )
        {
            cout<<"YES";
            flag=1;
            break;
        }
        
    }
    if (flag==0)
    {
        cout<<"NO";
    }
    
    return 0;
}
