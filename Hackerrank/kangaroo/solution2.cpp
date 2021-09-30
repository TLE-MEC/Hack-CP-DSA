// LOGIC:
// First, we compare the first kangaroo's location & rate with the second one.
//      if the first kangaroo's location & rate both are higher than the second or vice versa,
//      there's no way both will reach same location at any point.
// Second, if the location & rate of both the kangaroos are same, 
//      then they will both reach at the same time.
// Third, if both the kangaroos have same location but dofferent rates,
//      then again no chance of reaching together.
// ELSE, we calculate a variable 'y' which can make both their final locations same.
// Then we check if the value of 'y' can satisfy the given location & rate value.
//  If yes, then they reach together
// Else they don't.

// CODE in C++ :

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int x1,v1,x2,v2;
    cin>>x1>>v1>>x2>>v2;

    // checking initial conditions
    if((x1>x2 && v1>v2) || (x2>x1 && v2>v1))
        cout<<"NO"<<endl;
    else if(x1==x2 && v1==v2)
        cout<<"YES"<<endl;
    else if(v1==v2)
        cout<<"NO"<<endl;
    else
    {
        // finding the 'y' that can satisfy x,v
        long int y = abs((x2-x1)/(v1-v2));
        // check if the 'y' satisfies the given x,v of kangaroos
        if(x1+v1*y == x2+v2*y)
            cout<<"YES"<<endl;
        else   
            cout<<"NO"<<endl;
    }

    return 0;
}

// Sample test-case:
// I/P: 0 3 4 2
// O/P: YES
// I/P: 0 2 5 3
// O/P: NO
