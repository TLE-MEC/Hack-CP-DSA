class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length==1)
            return true;
        int dist = 0;
        for(int i = 0; i < nums.length; i++){
            dist=Math.max(dist, nums[i]);
            if(dist==0 && i!=nums.length-1)
                return false;
            dist--;
        }
        return true;
    }
}