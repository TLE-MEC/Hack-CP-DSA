// here we have to count minimum seconds it takes to open or close the doors in left or right.
// all the doors in left and right either should be open or should be closed

#include<iostream>
using namespace std;

int main(void){
    int n;
    cin>>n;
    
    // here we are storing the user input in a 2-D array.
    int a[n][2];
  
    // here lo means left open, lc means left closed, rc means right closed and ro means right open.
    int lo=0,lc=0,rc=0,ro=0;
    
    // here we have counted no. of doors in left and right which are open and closed.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin>>a[i][j];
            if (j==0 && a[i][0]==1)
            {
                lo++;
            }
            else if (j==0 && a[i][0]==0)
            {
                lc++;
            }
            else if (j==1 && a[i][1]==1)
            {
                ro++;
            }
            else if (j==1 && a[i][1]==0)
            {
                rc++;
            }
            
        }
        
    }
    
    // Now here we count the number of seconds and store it in the variable count.
    int count=0;
    if (lo>=lc)
    {
        count=count+n-lo;
    }
    else
    {
        count=count+n-lc;
    }
    
    if (ro>=rc)
    {
        count=count+n-ro;
    }
    else
    {
        count=count+n-rc;
    }
    
    cout<<count;
    
    return 0;
}
