#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;//number of test cases
    cin>>t;
    while(t--){
        int n;//input the number of sticks
        cin>>n;
        int a[n],i;// for each valid i, the initial height of the stick in the i-th holder is A[i]
        set<int>s;
        for( i=0;i<n;i++){// for each stick
            cin>>a[i];
        }
        for( i=0;i<n;i++){
            if(a[i]!=0){
            s.insert(a[i]);// avoid all those height which is repeated
        }
        
        }
       
        cout<<s.size()<<endl;//print the size of set
    }

	return 0;
}
