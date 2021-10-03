#include<iostream>
using namespace std;
int main()
{
    int x,h,n;
    cin>>n>>h>>x; /*Taking input of n=number of time zones chef can travel to,
    h=number of hours needed for chef to solve that question,
    and x=number of hours left with chef*/
    int t[n];   //taking an array of size n
    string f="yes"; //initiating a temporary variable f
    for(int i=0;i<n;i++)
        cin>>t[i];  //taking input of the timezones to which chef can jump
    for(int i=0;i<n;i++)
    {
        if(t[i]+x>=h)   /*If  time left with chef +any one of the timezones to 
        which he can jump is greater than the required time to solve the 
        problem then he can jump to that time and solve the problem.Otherwise
        he wouldnt be able to solve that problem*/
        {
            cout<<f;
            exit(0); /*when we get the required time zone our work is done
            and so we exit from the program*/
        }
    }
    f="no";
    cout<<f;
    return 0;
}