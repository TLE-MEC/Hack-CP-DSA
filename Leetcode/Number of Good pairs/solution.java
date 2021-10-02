//first we have to initialize count = 0 which will be our answer
//run an outer loop till the last element (int i=0;i<nums.length;i++);
//run an inner loop from index i+1 to last element to compare each element with index i for(int j=i+1;j<nums.length;j++)
// we are running inner loop from i+1 because condition is given that the index i should be always less than index j, therefore no neeed to go back to check.
//example, for i=0; j = 1, j=2, j=3, j=4 .... j=n-1 where n = nums.length;
    //checking if nums[i]==nums[j] and i < j , if this condition is true than add 1 to count, else move to another iteration
//this loop will run till all the elements of the array are compare to each other taking condition in mind (i<j).
// we return the count, which is the final answer.

class Solution {
    public int numIdenticalPairs(int[] nums) {
        int count = 0;                                      
        for(int i=0;i<nums.length;i++){                     
            for(int j=1;j<nums.length;j++){                 
                if(nums[i]==nums[j] && i<j){
                    count++;
                }
            }
        }
        
        return count;
        
        }
}
