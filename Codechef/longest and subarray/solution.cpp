#include <bits/stdc++.h>
using namespace std;
//logic:we will get longest subarrays with +ve sum only between 1,2,4,8..... i.e 2^n
//beacuse (2^n)&(2^n-1)=0 which makes subarrays & as zero 

//this function is to get nearest to left 2^n of given no. ,eg 8 for 15
int setBitNumber(int n)
{
    int k = (int)(log2(n));
    return pow(2,k);
}
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        long num;
        cin >> num;
        //if num is 2^n itself 
        if(((num)&(num-1))==0 && num!=1)
        {
            cout<<num/2<<endl;
        }
        else
        {
            long ans = setBitNumber(num);
            long temp=num-ans+1;
            if(temp<ans/2)
            {
                temp=ans/2;
            }
            cout<<temp<<endl;
        }
    }
    return 0;
}
