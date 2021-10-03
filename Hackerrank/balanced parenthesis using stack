#include<iostream>
#include<stack>
using namespace std;


string isBalanced(string s) {
    stack<int>st;  

   
   for(int i =  0 ; i< s.length(); i++) {
       
       switch(s[i]) {
               
           case '[' :
           case '(' :
           case '{' :
                st.push(s[i]);
                    break;
               
           case ']' :
               if(st.empty() || st.top()!='[')
                   return "NO";
               
               //otherwise pop
               st.pop();
               break;
               
           case '}' :
               if(st.empty() || st.top()!='{')
                   return "NO";
               
               //otherwise pop
               st.pop();
               break;
               
           case ')' :
               if(st.empty() || st.top()!='(')
                   return "NO";
               
               //otherwise pop
               st.pop();
               break;
               
       }
   }
    return st.empty() ? "YES" : "NO";
               
               
         
} 

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string s;
        cin >> s;
        string result = isBalanced(s);
        cout << result << endl;
    }
    
}
