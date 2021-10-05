#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Solution
{
public:
    int minAddToMakeValid(string S)
    {
        stack<int> st; // Create a stack to store indices
        int n = S.length();
        for (int i = 0; i < n; i++)
        {
            // If S[i] is a closing bracket and the stack top is an opening bracket, we got a valid pair, and Hence we can pop out the opening bracket present at the top of the stack.
            if (st.size() != 0 && S[st.top()] == '(' && S[i] == ')')
            {
                st.pop();
            }
            else
            {
                // Push to stack (It can be an opening or a closing bracket)
                st.push(i);
            }
        }
        // Now, Stack must contain the indices of the brackets who needs to pair up to form a valid Parentheses.
        return st.size(); // Stack size will give the count of minimum brackets to be added to make the Parentheses valid
    }
};