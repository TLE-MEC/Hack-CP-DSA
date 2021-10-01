#include <bits/stdc++.h>
#include <stack>

using namespace std;

/************************************EDITABLE PART***************************/
string isBalanced(string s) {
    int length = s.length();
    int i=0;
    
    stack<char> stcks;
    for(int i=0; i<length; i++){
        // insert open bracket parts to stack
        // if there is close bracket but no open bracket, the bracket not balanced
        // if the close bracket not matched the open bracket, the bracket not balanced
        // id the close bracket matched the open bracket, erase open bracket from stacks
        // iterate
        switch(s[i]){
            case '(':
            case '{':
            case '[':
                stcks.push(s[i]);
                break;
            case ')':
                if(stcks.empty() || (stcks.top() != '('))
                    return "NO";
                stcks.pop();
                break;
            case '}':
                if(stcks.empty() || (stcks.top() != '{'))
                    return "NO";
                stcks.pop();
                break;
            case ']':
                if(stcks.empty() || (stcks.top() != '['))
                    return "NO";
                stcks.pop();
                break;
        }
    }
    if (stcks.empty())
        return "YES";
    else
        return "NO";
}
/******************************************************************************/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
