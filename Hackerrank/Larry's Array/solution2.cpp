#include <bits/stdc++.h>
using namespace std;
#define  pb push_back

int main()
{
    
    //taking input of test cases
    int t; cin>>t;
    while(t--)
    {

        int n; cin>>n;
        //increasing dimenstion of array to fit for 1 based indexing
        int a[n+1]; a[0]=0; 
        int b[n+1]; b[0]=0;
        for(int i=1;i<=n;i++)
        {
             cin>>a[i];
             //storing index of the element 
             b[a[i]]=i;
        }

        int no=1;
        //running loop until we have'nt sorted the array
        while(no!=n-1)
        {
            //starting with 1st minimum element 
            int ind=b[no];
            //element needs to be shifted in case its index is greater than itself
            if(ind>no)
            {
                int diff=ind-no;
                b[no]=no;
                //bringing shift in the indexes
                for(int i=no;i<ind;i++)
                {
                    b[a[i]]++;

                }
                //also shifting the elements in the array
                for(int i=ind;i>no;i--)
                {
                    swap(a[i],a[i-1]);
                }
                //checking for odd difference in positions
                if(diff&1){
                    b[a[no+1]]++;
                    b[a[no+2]]--;
                    swap(a[no+1],a[no+2]);
                }
            }
            no++;

        }
        //if last element is n it implies sorting was successful
        if(a[n]==n) 
            cout<<"YES\n";
        else 
            cout<<"NO\n";
    }

}
