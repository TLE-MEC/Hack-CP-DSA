// points to consider:  (Aproach- Bit manupulation)     
    // 1) At first we are creating a mask which will be containing 
    //    all the set bits acccording to the string given
    //    example : mask for acd will be (...00001101)
    // 2) Second check if the corresponding bit of the letters of a string is set or not in the mask.
    //    if all letter are set then string is a consistent string.
             
class Solution {
    public int countConsistentStrings(String s, String[] words) {
    
        //mask
        int mask=0;
        
        int n=s.length();
        
        //mask is updated here for the given allowed string
        for(int i=0;i<n;i++){
            mask = mask | 1<<(s.charAt(i)-'a');//set the bit according to the index of alphabets eg: for c,third bit will be set
        }
      
        //number of allowed strings count
        int ans=0;
        
        
        for(String x : words){
            
            //count of letters of x present in allowed string
            int c=0;
            
            //traversing through the string
            for(char ci: x.toCharArray()){
                if((mask & (1<< (ci-'a')))!=0)//checks if the corresponding letter's bit is set or not in the mask
                    c++;
                else //if not set break the loop 
                    break;
            }
            if(c==x.length()) // if all the letters of the element is present in the allowed string increment ans.
                ans++;     
        }
        
   return ans;
        
    }
}