
#include <bits/stdc++.h>
using namespace std;

string fairRations(vector<int> B) {
    int loaves=0,i=0,end = B.size()-1;
    while(i<end)
    {
        if(B[i]%2)   //we want odd numbers and 1 will be returned in case of odd which will eventaully run the conditional if as 1 means true 
        {
            B[i]++;B[i+1]++;
            loaves+=2;
        }
        i++;
    }
    if(B[end]%2)   // this will return 1(True for if condition) only when end element is odd which means that all the elements can not be converted into even so return "NO"
    {
        return "NO";
    }
    return to_string(loaves);     //to_string function converts int to string type
}
int main()
{
    int n,x;
    
    cin>>n;
    vector<int>A(n);
    for(int i=0;i<n;i++)
    {
    cin>>x;
    A.push_back(x);
    }
    cout<<fairRations(A);
    return 0;
}