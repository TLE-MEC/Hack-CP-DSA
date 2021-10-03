class Solution {
public:
    string truncateSentence(string s, int k) {
        int a=0,l;                   // taking variavle a and l
        string ans={};               // string named ans
        
      for (int i=0;i<s.length();i++){
          if(s[i]==' ') a++;        // white space (' ') to count words
          if (a==k) {
              l=i;
              break;                // breaking loop as a equal to k is desired condition
          }
                     
      }
        ans=s.substr(0, l);         // give string of desired length
        return ans;                // returning the ans variable
    }
};
