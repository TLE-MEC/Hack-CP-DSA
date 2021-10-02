class Solution {
public:
    string truncateSentence(string s, int k) {
        // sp is counter for number of spaces
        int i,sp=0;
        for(i=0;i<s.size();i++){
            // if there is any spaces then increment sp
            if(s[i]==' '){
                sp++;
            }
            // if sp is equal to the number of word that need are required then truncate the string from ith position to the end
            if(sp==k){ 
                s.erase(s.begin()+i , s.end());
                return s;
            }                
        }
        return s;
    }
};