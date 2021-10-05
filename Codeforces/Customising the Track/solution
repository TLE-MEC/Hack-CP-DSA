    #include<bits/stdc++.h>
    using namespace std;
    
    //Time Complexity : O(n)
    //Space Complexity : O(1)
    
    void run_fun()
    {
       long long  int n; cin>>n; //
       long long int s=0; //sum of inputs
       long long int in; //input variable
        for(long long int i=0;i<n;i++)
        {
         cin>>in;
         s+=in;
        }
        // the number of cars will be distributed as evenly as possible
        long long int fir=s%n; //first distribution 
        long long int sec=(n-s%n); //remaining distribution 
        
        cout<<fir*(sec)<<endl;
     
    }
    int main() 
    {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t; cin>>t;
    while(t--) run_fun();
    return 0;
    
    }
