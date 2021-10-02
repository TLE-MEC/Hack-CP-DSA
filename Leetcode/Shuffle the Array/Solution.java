class Solution {
    public int[] shuffle(int[] nums, int n) {

        int[] ans = new int[nums.length];

        int remInd = 0;

        for(int i=0; i<nums.length; i+=2){
            ans[i] = nums[remInd];
            ans[i+1] = nums[remInd + n];
            remInd++;
        }
        return ans;
    }
}