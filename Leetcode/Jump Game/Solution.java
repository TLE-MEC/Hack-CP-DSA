class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length==1)
            return true; //If there is only one element, then it is possible to jump to it.
        int dist = 0; 
        for(int i = 0; i < nums.length; i++){
            dist=Math.max(dist, nums[i]); //Find the farthest distance that can be reached from the current position.
            if(dist==0 && i!=nums.length-1)
                return false; //If the farthest distance is 0, then it is impossible to reach the end.
            dist--; //Reduce the farthest distance by 1.
        }
        return true; //If the farthest distance is not 0, then it is possible to reach the end.
    }
}