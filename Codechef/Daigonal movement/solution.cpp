/*In this problem we observe that the points to which we can move are symmetric across the x and y axis.
Thus if the movement to absolute(x,y) is possible then the movement to (x,y) is also possible.
Then we observe that the points that we can move to satisfies any of the 2 conditions:
1)both x and y of that point is odd.
2)both x and y of that point is even
time complexity=O(1) space complexity=O(1) */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y; //taking input of the point to be checked.
        if(x<0) //abosute(x)
            x=-x;   
        if(y<0) //absolute(y)
            y=-y;
        if(x==y||((x%2==1)&&(y%2==1))||((x%2==0)&&(y%2==0)))    //checking conditions for possible movement
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}