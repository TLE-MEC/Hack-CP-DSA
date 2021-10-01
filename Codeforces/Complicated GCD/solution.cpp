#include <bits/stdc++.h>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); //speeds up the code execution
/*
 We examine two cases:
a=b — the segment consists of a single number, hence the answer is a.
a<b — we have gcd(a,a+1,a+2,...,b)=gcd(gcd(a,a+1),a+2,...,b)=gcd(1,a+2,...,b)=1.
 */
int main(){
    FIO
//using the inbuilt gcd function for such a large input will fail
    string a,b; //input as string because the input is very large, which cannot be stored in any c++ numerical data type
    cin>>a>>b;
    if(a==b)
    {
        cout<<a;
    }
    else cout<<1;

    cout<<'\n';
    return 0;
}
