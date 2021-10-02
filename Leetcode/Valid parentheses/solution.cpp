//Basic idea: ()--> true, {}--> true, []-->true,)(-->false,)[](-->false
//Create an empty stack to store the parentheses
//if the value is equal to an opening bracket push(add) the bracket to the stack
//if the char is a closing bracket it must have a opening bracket before for the answer to be true
//empty stack or closing brackets before corresponding opening bracket gives false

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto i:s)
        {
            if(i=='(' or i=='{' or i=='[') st.push(i);  //push opening tags
            else
            {
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) return false;
                st.pop();  //if control reaches here, it means we have got the right pair of brackets, so just pop it.
            }
        }
        return st.empty();  //if there are no invalid parentheses this line returns true else false
    }
};
