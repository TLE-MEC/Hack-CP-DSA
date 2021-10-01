class Solution {
 public char nextGreatestLetter(char[] letters, char target) {
        
        int start = 0;
            int end  = letters.length - 1;
            
            while(start <= end){
                
                int mid = (start + end)/2;
                //if target element is less than middle element 
                if(target < letters[mid] ){
                    end = mid -1;
                }
                //target element is greater than mid element
                else {
                    start = mid +1;
                }
            }
            //condition of the wrap around 
            return letters[start%letters.length];
    }
}