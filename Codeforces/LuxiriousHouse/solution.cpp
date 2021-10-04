#include<bits/stdc++.h>
using namespace std;
int main()
{
    fast;
    // Take length of array from user
    long long int n;
    cin>>n;
  // create array of size n and start filling it
    long long int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
  // let end element of array be max element
    long long int max=a[n-1];
  // now make it zero because no element on its right side greater then it
    a[n-1]=0;
    for(int i=n-2;i>=0;i--)
    {
      // check if current element if greater then max
      //then make max equal to current element and cureent element to zero
        if(a[i]>max)
        {
            max=a[i];
            a[i]=0;
        }
      // if current element is smaller then max 
      // make it differece between max and current element and add 1 to make it bigger
        else
        {
            a[i]=max-a[i]+1;
        }
    }
  // print all value of array
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
