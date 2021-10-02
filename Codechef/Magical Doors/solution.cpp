#include <iostream>
#include <string>
using namespace std;

int main()
{

    int t;
    cin >> t;

    //Going over each test case
    while (t--)
    {
        string s;
        cin >> s;

        //storing no. of times we need to use magic wand
        int count = 0;

        for (int i = 0; i < s.length(); i++)
        {
            //at each step acc to the no. of times wand used
            //we calculate whether curr will be 0 or 1
            //ex: if wand used 3 times, if in original it is 0
            //we need to consider it as 1 bcz 0->1->0->1
            if(count%2 != 0){
                if(s[i]=='1'){
                    s[i]='0';
                }
                else{
                    s[i]='1';
                }
            }
            if(s[i] == '0') //if curr=0, we need to use wand and count increses
            {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}