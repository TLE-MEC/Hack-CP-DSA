public class Solution {
    //helper function
    boolean helpInPartition(int nums[],boolean visited[],int start,int k,int currentSum,int targetSum)
    {
        //when there are no more subsets left to make
        if(k==0)
            return true;
        if(currentSum>targetSum)
            return false;
        //if current sum equals target sum,we are left with k-1 subsets to make
        if(currentSum==targetSum)
            return helpInPartition(nums,visited,0,k-1,0,targetSum);
        for(int j=start;j<nums.length;j++)
        {
            //if nums[j] is already included in a subset skip this iteration
            if(visited[j])
                continue;
            //let us assume nums[j] is a part of the current subset
            visited[j]=true;
            //current sum < target sum,we look for elements beyond j
            if(helpInPartition(nums,visited,j+1,k,currentSum+nums[j],targetSum))
                return true;
            //if nums[j] is not a part of the current subset , we mark it unvisited
            visited[j]=false;
        }
        return false;
    }
    public boolean canPartitionKSubsets(int[] nums, int k) {
        int sum=0;
        for(int i:nums)
            sum+=i;
        //nums can be divided into k equal sum subsets only if the sum of its elements is divisible by k
        if(sum%k!=0)
            return false;
        //visited array to keep track where an element is already a part of a subset or not
        boolean visited[]=new boolean[nums.length];
        return helpInPartition(nums,visited,0,k,0,s/k);
    }
}
