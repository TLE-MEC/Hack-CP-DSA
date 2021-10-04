/*As we know there are four directions and as per question chef is pointing north
and when he turns 90 deg clockwise his direction changes and he points east
if he turns again he points south and after 4 turns from starting position he will be pointing north again
hence if we divide the number of turns by 4 ,the reminder gives us the turns with
respect to the original position as turning 4 turns cause net rotation 0.*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)  //running t testcases
    {
        int n;
        cin>>n; //number of seconds input(number of turns =number of seconds)
        if(n%4==0)  //check net movement
            cout<<"North"<<endl;
        else if(n%4==1)
            cout<<"East"<<endl;
        else if(n%4==2)
            cout<<"South"<<endl;
        else
            cout<<"West"<<endl;
    }
}