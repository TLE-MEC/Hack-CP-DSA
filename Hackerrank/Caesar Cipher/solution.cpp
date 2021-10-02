/* *****This code has a time complexity of the order O(n)***** */

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    int i,j,n,k;
    cin>>n; //number of characters in the string
    string s;
    cin>>s; //taking string as the input
    cin>>k; //number of rotations that are required
    int len=s.length(); //length of the string
    string str;
    int a=0;
    int b=0;
    char c;
    int result=0;
    int x=0;
    int y=0;
    char alphabet1[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'}; //all the alphabets in lowercase
    char alphabet2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'}; //all the alphabets in UPPERCASE
    for(i=0;i<len;i++)
    {
        a=(int)s[i];
        if((a>=65 && a<=90) || (a>=97 && a<=122)) //checking if the character is an alphabet or not and wehther is in boundary range or not
        {
            if(a>=65 && a<=90 && a+k>90) //checking that after roatation of an UPPERCASE character, it becomes some another type of character or not
            {
                x=abs((int)s[i]-65); //we get back the UPPERCASE character like this
                y=((x+k)%26); //rotating it
                s[i]=alphabet2[y]; //storing it after roatation
            }
            else if(a>=97 && a<=122 && a+k>122) //checking that after roatation of a lowercase character, it becomes some another type of character or not
            {
                x=abs((int)s[i]-97); //we get back the lowercase character like this
                y=((x+k)%26); //rotating it
                s[i]=alphabet1[y]; //storing it after roatation
            }
            else
            {
                b=a+k; //no rotation required as it is wihtin the boundaries
                c=(char)b;
                s[i]=c;
            }
        }
    }
    cout<<s; //display the newly encoded string
    return 0;
}