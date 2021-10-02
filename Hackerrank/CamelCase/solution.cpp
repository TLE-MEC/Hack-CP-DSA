#include <bits/stdc++.h>

using namespace std;

/*
The ides is to find the no. of words in camelCase strings first of all in camelCase write a string such that the all the letters
of the first word are written in lower case and for all the other words the first letter is written in uppercase
 */

int camelcase(string s)
{
    int words = 1;
    //initially any camelCase word will have atleast 1 word

    //now we will iterate over the whole string length and whenver we hit an uppercase letter that means a new word is starting
    for (int i = 0; i < s.length(); i++)
    {
        if (isupper(s[i]))
        {
            words += 1;
            //and hence we got to know new word is starting so we increased the words by 1
        }
    }
    return words;
}

int main()
{
    //Lets take the input string insput as s
    string s;
    //getline is use to tske input of all strings with or without space
    getline(cin, s);

    int result = camelcase(s);
    //call the function and storing its value in result

    cout << result << "\n";
    //printing the result

    return 0;
}
