class Solution {
    public int[] buildArray(int[] nums) {
        int[] ans = new int[nums.length];//Initialized an array to store the result//
        
            for (int i=0;i<nums.length;i++){//for loop to traverse through nums[]//
                if (nums[i]<=nums.length){//Checks if i is less than the length of nums[]//
                    ans[i]=nums[nums[i]];//Appending nums[nums[i]] as required//
                }
                
                
            }
            
     return ans;       
    }

}