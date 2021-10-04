// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
char* reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        char *ch=reverse(str,len);
        cout<<ch;
        cout<<endl;
    }
        return 0;
}

// } Driver Code Ends


//return the address of the string
char* reverse(char *s, int len)
{
    //code here
    stack<char> st;
    /*first we push all characters of string in a stack*/
    for(int i=0;i<len;i++){
        st.push(s[i]);
    }
    /*Now, pop out the elements from stack and initailize them in the string*/
    /*This works because of last in first out property of stack*/
    for(int i=0;i<len;i++){
        s[i] = st.top();
        st.pop();
    }
    return s;
}