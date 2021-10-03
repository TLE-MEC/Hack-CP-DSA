#include<iostream>
using namespace std;

int main(void){
    int n;
    cin>>n;
    int a[n][2];
    int lo=0,lc=0,rc=0,ro=0;
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
