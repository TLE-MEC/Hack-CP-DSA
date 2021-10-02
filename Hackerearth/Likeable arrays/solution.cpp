#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int cases;
    cin>>cases;
    while(cases--){
        int n,num;
        cin>>n;                                             // Input size of array
        map<int,int>count;                                  // Declare a map which where value is equal to number of occurance of the key in the array        
        for(int i = 0 ; i < n ; i++){   
            cin>>num;
            count[num]++;
        }
        int ans = 0;
        for(auto it:count){                                 // Transverse the map
            if(it.first == it.second){                      // If key and value are same then do nothing
                continue;
            }
            else{                                           // Else increase ans by minimum of (it.second - 0 and | it.first - it.second | )
                ans += min(abs(it.first - it.second),abs(it.second));
            }
        }
        cout<<ans<<"\n";                                     // Print the answer
    }
return 0;
}