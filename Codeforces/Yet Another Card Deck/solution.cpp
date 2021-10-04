#include <bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;
void solve()
{
   int n ,q;
    cin >> n >> q; // take inputs of number of cards and color
   int a[n];
    for(int i = 0; i < n; i++) // take input of cards
        cin >> a[i];           
     int x, y;
     //here we check that first instance of x found we store its location in array. Then we print location+1 as zero based array.
    for(int j=0;j<q;j++)  
    {
        int f = 0;
        cin >> x;           // take input of color
        for (int i = 0; i < n; i++) 
        {
            if (a[i] == x)     // if we find element == color we make f =1
            {
                y = i;
                cout << y + 1 << " ";
                f =1;
                break;
            }
        }
         //if it is present we make f=1 and then swap all elements which moves the elements forward cyclically by 1.
      // x becomes a[0] , a[0] becomes x
      //a[1] becomes x which is a[0] , x which was a[0] becomes a[1] and so on...
        if(f)   // if color if found we swap
        {
            for(int i = 0; i <= y; i++) 
                swap(x, a[i]);
            
        }
    }
}
int main()
{
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
 int  t=1;
 //cin>>t;
 while(t--) 
 solve();
 return 0;
}
