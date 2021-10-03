/*
This question can be solved using stack datastructue in O(n) time complexity. Where n is length of input string.

Approach:

Keep ignoring element till element at top of stack matches the next element. 
Add to stack only if element at top of stack is different than current element we are considering in loop.
Pop from stack if element at top of stack matches current element we are considering in loop
*/
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty() || st.top()!=s[i])
                st.push(s[i]);
            else{
                st.pop();
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};