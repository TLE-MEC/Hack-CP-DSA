#include <iostream>
#include<string>
using namespace std;

int main()
{

    int t;
    cin >> t;
    //iterating over each test case
    while (t--)
    {
        //we need to find n digit number divible by 3 but not by 9
        int n;
        cin >> n;
        
        //if single digit, then ans will be 3
        if(n==1){
            cout<<"3"<<endl;
        }
        else{
        //for req digits more than 1,
        //simple approach could be
        //have 2 at starting and 1 at ending place and rest 0 n-2 times
        //which makes the sum of digits 3 => div by 3 but not by 9
        string ans = "2";
            for (int i = 1; i < n-1; i++)
                ans += "0";
            ans+="1";    
        cout<<ans<<endl;
        }
        
    }

    return 0;
}