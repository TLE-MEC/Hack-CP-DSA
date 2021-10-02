class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length()==0){
            return 0;
        }     
        
        //Loops thorugh the haystack
        for(int i=0;i<=haystack.length();i++){  
            
            //Checks whether the there is a possiblity of needle substring after the given index
            if(i+needle.length()>haystack.length()){
                return -1;
            }
            
            //Compares a substring of needle's length from the given index and if its true return the index
            if(needle.compare(haystack.substr(i,needle.length()))==0){
                return i;
            }
        }
        return -1;
    }
};
