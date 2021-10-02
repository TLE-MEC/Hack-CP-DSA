class Solution {
    public int[] runningSum(int[] nums) {
        int sum=0;
        int[] runningSum=new int[nums.length];//Initialising an array to store the sum//
        for(int i=0;i<nums.length;i++){//For loop to iterate through the array elements//
            sum=sum+nums[i];//Calculates sum from index 0 to i//
            runningSum[i]=sum;//Storing the required sum in the resultant array//
        }
        return runningSum;
    }
}