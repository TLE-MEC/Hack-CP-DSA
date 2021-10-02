/*
Ciel and Receipt solution in c++
Author - Keshav Prajapati
*/
#include <iostream>
using namespace std;

int main() 
{
    int t,m,n,count=0,cal=1;
    cin>>t;
    int a[t];
    for(int i=0;i<t;i++)
        cin>>a[i];
    for(int i=0;i<t;i++)
    {
        m=n=a[i];
        for(int j=1;j<1000;j++)
        {
            if(m>2048)
            {
                count=m/2048;
                int c=m%2048;
                if(c==0)
                {
                    cout<<count<<endl;
                    count=0;
                    break;
                }
                else
                    m=n=c;
            }
            cal*=2;
            if(cal==n)
            {
                cout<<++count<<endl;
                cal=1;
                count=0;
                break;
            }
            if(cal>m)
            {
                count++;
                int c=cal/2;
                cal=1;
                m=m-c;
                if(m==2)
                {
                    cout<<++count<<endl;
                    count=0;
                    break;
                }
                if(m==1)
                {
                    cout<<++count<<endl;
                    count=0;
                    break;
                }
                if(m==0)
                {
                    cout<<count<<endl;
                    count=0;
                    break;
                }
            }
        }
    }
	return 0;
}