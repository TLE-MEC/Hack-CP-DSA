

Video solution
https://www.youtube.com/watch?v=WpYHNHofwjc

class Solution {
public:
    string longestPalindrome(string s) {
        
        // we are checking if the string is empty or contains only 1 character then we will return empty string 
        if(s.empty() || s.length()<1)
            return "";
        
        int maxLenBegin=0;
        int maxLen=1;
        int mid=0;
        while(mid < s.length())
        {
            
            int midBegin = mid;
            int midEnd = mid;
            
            //EVEN - for even length string we will check if midEnd+1 is equal to midEnd then we will increament the midEnd 
            while(midEnd < s.length() && s[midEnd] == s[midEnd+1])
                midEnd++;
            
            mid = midEnd + 1;
            
            //ODD - now we will defin two variable left and right and we will assign midBegin to left and midEnd to right
            // if the length of string is odd then both left and right will be having same value because midBegin will be == midEnd. 
            int left = midBegin;
            int right = midEnd;
            
    // now the time to expand to left and right side from the middle of the string with the basic conditions as below
            while(left - 1 >= 0 && right + 1 < s.length() && s[left - 1] == s[right + 1])
            {
                left--;
                right++;
            }
    // when the above condition stop it will be having some pallindromic string indexes in left and right
    // to get the len we will subtract the start aka " left" and end aka "right" here :
            int currLen = right - left + 1;
            
            if(currLen > maxLen)
            {
                maxLenBegin = left;
                maxLen = currLen;
            }
        }
    //in c++ substr(startingIndex, Ending Index) is to get the substring fo a string with indexs 
        return s.substr(maxLenBegin, maxLen);
    }
};