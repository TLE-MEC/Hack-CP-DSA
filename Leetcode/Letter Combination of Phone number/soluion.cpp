  class Solution {
        private:
        vector<string> str={"","","abc","def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> Getanswer;

public:
void answer(string digits ,int counter , string &ans){
    if(counter == digits.size()){
        
        Getanswer.push_back(ans);
        return ;
    }
    char ch = digits[counter];
    string chars = str[ch-'0'];

    for(int i =0;i<chars.size();i++){
        ans.push_back(chars[i]);
        answer(digits,counter+1,ans);
        ans.pop_back();
        }

}
    vector<string> letterCombinations(string digits) {
    if(digits.size()==0){
            return Getanswer;
        }   
string ans="";
        
        
             answer(digits, 0 ,ans);
 
        
        
         return Getanswer;
    
    }
};