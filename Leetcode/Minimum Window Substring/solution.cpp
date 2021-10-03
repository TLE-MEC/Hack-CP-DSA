/** Approach: First Calculate the number of times a character appeared in the string t, then keep a left, right pointers from start of the string s and move right pointer 
to right we get all the characters of string t in string s and move left pointer to the right to make minimum. **/


class Solution {
public:
    string minWindow(string s, string t) {
        vector <int> hash(256,0);
        for(char c : t)
            hash[c]++;
        int start = 0, end = 0;
        int counter = 0, head  = 0;
        int len = INT_MAX;
        while(end < s.size()){
            if(hash[s[end]] > 0)
                counter++;
            hash[s[end]]--;
            end++;
            while(counter == t.size()){
                if(end - start < len){
                    len = end - start;
                    head = start;
                }
                if(hash[s[start]] == 0)
                    counter--;
                hash[s[start]]++;
                start++;
            }  
        }
        if(len == INT_MAX)
            return "";
        else
            return s.substr(head, len);
    }
};