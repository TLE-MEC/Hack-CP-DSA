class Solution {
    public int[] shuffle(int[] nums, int n) {

        int[] ans = new int[nums.length];

        int remInd = 0;

        for(int i=0; i<nums.length; i+=2){
            ans[i] = nums[remInd]; // adding i'th number to the ans array
            ans[i+1] = nums[remInd + n]; // adding (remInd+n)'th number to the ans array
            remInd++;
        }
        return ans;
    }
}