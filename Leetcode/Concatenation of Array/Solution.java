class Solution {
    public int[] getConcatenation(int[] nums) {
        int[] ans = new int[2*(nums.length)];//Initialised an array of size 2*n to store the result//
        for(int i=0; i<ans.length;i++){//For loop to traverse through ans[]//
            if(i<nums.length){//Checks if i is less than the length of nums//
                ans[i]=nums[i];//If yes, then copy the string to answer//
            }
            else
                ans[i]=nums[i-nums.length];//else append nums to the end of ans//
        }
     return ans;   
    }
}