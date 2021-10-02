#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; 
    cin >> t; //taking input for number of test cases

    while (t--)
    {
        string s; 
        cin >> s; 

        int n = s.length(); //finding out length of input string

        int flag = 0; 

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] < s[i + 1]) //seeing if the alphabets of string are arranged in descending order 
                flag = 1;
        }

        if (flag)
        {
            int minimax; //variable to store ascii value of alphabet

            for (int i = n - 2; i >= 0; i--)
            {
                minimax = 123; // any ascii value greater than that of alphabets

                for (int j = i + 1; j < n; j++) // finding smallest character which is greater than s[i]
                {
                    if (s[j] > s[i])
                    {
                        minimax = min(minimax, (int)s[j]); //calculating minimum
                    }
                }

                if (minimax != 123)
                {
                    for (int j = i + 1; j < n; j++)
                    {
                        if ((int)s[j] == minimax)
                        {
                            int temp = s[i]; // swapping the smallest found character with s[i]
                            s[i] = s[j];
                            s[j] = temp;
                            break;
                        }
                    }
                    sort(s.begin() + i + 1, s.end()); //sorting the string from s[i] till end of string
                    break;
                }
            }

            cout << s << '\n'; // prinitng the final string
        }
        else
        { 
            cout << "no answer" << '\n';  //if flag is equal to zero
        }
    }
}
