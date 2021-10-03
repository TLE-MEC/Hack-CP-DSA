#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define pb push_back
#define pf push_front
using namespace std;
int main()
{
fastread(); //include this if you have large inputs
  /*LOGIC->Since we are required to find wether the body is in equilbrium or not, using 
  basic understanding that the sum of vector in each x,y & z direction should be zero
  1->add all x components
  2->add all y componnets
  3->add all z components
  if x=y=z=0 then body is in equilibrium.*/
int t=1;
//cin>>t;
while(t--){
    int n;
    cin>>n;
    int x=0,y=0,z=0;
    for(int i=0;i<n;i++){
        int X,Y,Z;
        cin>>X>>Y>>Z;
        x=x+X;
        y=y+Y;
        z=z+Z;
    }
    if(x==0 && y==0 && z==0){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}
return 0;
}
