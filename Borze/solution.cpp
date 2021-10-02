#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define pb push_back
#define pf push_front
using namespace std;
int main()
{
fastread();
  /*We will be using a very simple approach, we will just take
  the input as a string and we will be iterating through the string,
  if we encounter "." we will simply add "0" to the parent newly created ans
  string and if we encounter "-" then we will check accordingly wether the
  next upcoming character is "." or "-" .*/
int t=1;
//cin>>t;
while(t--){
    string s;
    cin>>s;
    cin.ignore();
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                ans=ans+"0";
            }
            else{
                if((i!= s.size()-1) && (s[i+1]=='.')){
                    ans=ans+"1";
                    i=i+1;
                }
                else{
                    ans=ans+"2";
                    i=i+1;
                }
            }
        }
        cout<<ans<<"\n";
}
return 0;
}
