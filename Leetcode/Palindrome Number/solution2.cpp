class Solution 
{
public:
    bool isPalindrome(int x) // Creating the function
    {
        string s = to_string(x); //converts the number to a string. For example: to_string(121) = "121"
        string r = ""; // An empty string
        
        for (int i = s.length()-1; i >= 0; i--) // Run a reverse loop
        {
            r += s[i]; // append each character to the string r.
        }
        
        if (s == r) // if the actual string is equal to the reversed string
        {
            return true; // return that the number is palindrome
        }
        return false; // if they are not equal: return the number is not a palindrome
    }
};