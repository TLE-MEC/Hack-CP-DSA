#include <bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
 
void solve()
{
string s;
cin>>s;
int l = s.length();
int flag=0;
for(int i=0;i<l;i++)
{
   if(s.at(i)=='a')
   flag++;
}
//see if string made up of only a
//if yes print NO s impossible
if(flag==l)
   NO
   //else add a in end and check if this new string is not a palindrone. if not print string +a else print a+ string +a
else
{
   YES
   string s1=s+'a';
   reverse(s1.begin(),s1.end());
   if(s1!=s+'a')
   cout<<s+'a'<<endl;
   else
   cout<<'a'+s<<endl;
}
label:
int y;
 
}
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int  t=1;
 cin>>t;
 while(t--) 
 solve();
 return 0;
}