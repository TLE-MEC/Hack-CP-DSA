#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v[3][3];
    vector<int> a;

    //taking input from user
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>v[i][j];
            a.push_back(v[i][j]);
        }
    }

    //defining a 2D array consisting of all the possbile combinations to solution
    int b[8][9]={{8,3,4,1,5,9,6,7,2},
    {4,9,2,3,5,7,8,1,6},
    {2,7,6,9,5,1,4,3,8},
    {6,1,8,7,5,3,2,9,4},
    {4,3,8,9,5,1,2,7,6},
    {2,9,4,7,5,3,6,1,8},
    {6,7,2,1,5,9,8,3,4},
    {8,1,6,3,5,7,4,9,2}};

    //this vector will consist of all the differences form each of the combinations
    vector<int> f;
    for(int i=0;i<8;i++)
    {
        int diff=0;
        for(int j=0;j<9;j++)
        {
            diff+=abs(b[i][j]-a[j]);
        }
        f.push_back(diff);
        
    }
    //sorting the solution vector
    sort(f.begin(),f.end());

    //minimum value lies at 0 index and that is our answer
    cout<<f[0];
}
