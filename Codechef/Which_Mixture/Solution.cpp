#include<bits/stdc++.h>
#define ll long long
#define cp() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
using namespace std;

int main(){
    cp();
    int T;
    cin>>T;
    while(T--){
        int A,B;
        cin>>A>>B;

        //If There is no solid
        if (A==0)
        {
            cout<<"Liquid"<<endl;
        }
        //If There is no Liquid
        else if(B==0){
            cout<<"Solid"<<endl;
        }

        else if (A>0 && B>0)
        {
            cout<<"Solution"<<endl;
        }
    }

    // The time complexity Of the code is O(T). 
    // The time complexity of if else conditions are O(1)
    return 0;
}