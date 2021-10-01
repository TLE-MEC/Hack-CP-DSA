class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
        string c=countAndSay(n-1);
        string ans="";
        stack<char> st;
        for(int i=0;i<c.length();i++)
        {
            if(st.empty())
            {
                st.push(c[i]);
            }
            else if(st.top()==c[i])
            {
                st.push(c[i]);
            }
            else if(st.top()!=c[i])
            {
                ans=ans+to_string(st.size())+st.top();
                int ij=st.size();
                for(int j=0;j<ij;j++)
                {
                   cout<<st.top();
                    st.pop();   
                    
                }
                st.push(c[i]);
            }
        }
        if(st.empty()==false)
        {
            ans=ans+to_string(st.size())+st.top();
        }
        return ans;
        
    }
};