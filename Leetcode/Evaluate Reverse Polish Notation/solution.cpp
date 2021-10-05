/** Approach: If the current token is a operand then push it into the stack. If the token is a operator, pop the top two operands 
from the stack then calculate result of the operation using the operator and two operands and push the result back into stack. 
Atlast, the stack will contain the result of evaluated reverse polish expression.**/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" ||tokens[i] == "*" ||tokens[i] == "/" ){
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                if(tokens[i] == "+")
                    s.push(a+b);
                else if(tokens[i] == "-")
                    s.push(b-a);
                else if(tokens[i] == "*")
                    s.push(a*b);
                else if(tokens[i] == "/")
                    s.push(b/a);
            }
            else{
              s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};