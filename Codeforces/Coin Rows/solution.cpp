#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int cases;
    cin>>cases;
    while(cases--){
        int n;
        cin>>n;
        vector <ll int> sum1(n+1,0);
        vector <ll int> sum2(n+1,0);
        for(int i = 1 ; i < n+1 ; i++)
        cin>>sum1[i];

        for(int i = 1 ; i < n+1 ; i++)
        cin>>sum2[i];

        for(int i = 1 ; i < n+1 ; i++)
        sum1[i] += sum1[i-1];

        for(int i = n-1 ; i > 0 ; i--)
        sum2[i] += sum2[i+1];

        ll int ans = 10000000000,temp1,temp2,temp;
        for(int i = 1 ; i < n+1 ; i++){
            temp1 = sum1[n] - sum1[i];
            temp2 = sum2[1] - sum2[i];
            temp = max(temp1,temp2);
            ans = min(ans,temp);
        }
        cout<<ans<<endl;
    }
return 0;
}