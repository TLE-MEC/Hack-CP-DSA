/*
Palindromes can be of two types:
    - even number of characters, like "abba"
    - odd number of characters, like "abcba"

The idea is to pick an element from the string and start expanding the window on both sides. This window is expanded till elements at both end are equal.
- For even number of characters, the boundary of expansion starts from [i,i+1]
- For odd number of characters, the boundary of expansion starts from [i,i]

For example:
string: abcba

for character c:
    - first window = c
    - second window = bcb
    - third window = abcba

Thus the maximum number length of substring here is 5.


*/


class Solution {
public:
    int res = 0;
    int countSubstrings(string s) {
        
        if(s.empty()) return 0;
        if(s.size() ==1) return 1; // every single character is a palindromic substring
        for (int i =0;i<s.size();i++)
        {
            expandFromMiddle(s,i,i);// odd expansion as explained above
            expandFromMiddle(s,i,i+1);// even expansion as explained above
        }
        
        return res;
    }
    void expandFromMiddle(string s,int low, int high){
        if(s.empty())
            return;
        while(low>=0 && high <s.size()&& s[low]==s[high]) // expand till the word is not exhausted and the end elements of the window are equal
        {
            low--;
            high++;
            res++;
            
        }
        
    }
};