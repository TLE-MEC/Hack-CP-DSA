/*

Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.

Runtime Complexity: O(log n)


*/


class Solution {
    public int searchInsert(int[] nums, int target) {
        int i;
        for(i=0; i<nums.length;i++){

            //first i am searching if the target already exists if yes then we break here

            if(target==nums[i]){
                break;
            }//if the given target doesnt exist we look for intermediate item after it and break
            else{
                if(target<nums[i]){
                    break;
                }
            }
        }

        //here we return the index of either target found or just intermediate
        return i;
    }
}