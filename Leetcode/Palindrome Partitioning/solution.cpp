/** Approach: Start taking from smallest substring if it is palindrome push the substring to the result continue till it is palindrome**/


class Solution {
public:
    vector<vector<string>> res;
    bool ispalindrome(string &s){
        int start = 0, end = s.size()-1;
        while(end >= start){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void f(string s, int start, int end, vector<string>contri){
        // base cases
     if(start > end)
         res.push_back(contri);
        // recursive step
        for(int i = start; i <= end; i++){
            string prefix = s.substr(start, i-start+1);
            if(ispalindrome(prefix)){
                contri.push_back(prefix);
                f(s, i+1, end, contri);
                contri.pop_back();
            }
            else
                continue;
        }
         
    }
    vector<vector<string>> partition(string s) {
        f(s, 0, s.size()-1, {});
        return res;
    }
};