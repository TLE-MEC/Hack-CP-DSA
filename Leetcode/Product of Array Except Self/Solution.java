class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        int[] leftProduct = new int[n];
        int[] rightProduct = new int[n];
        leftProduct[0] = 1;
        rightProduct[n-1] = 1;

        // Array ans used to save multiplication till its left
        // then another loop to get multiplication of right side of the number and then multiply it with ans[i] , 
        // that is the left side answer.
        // So left to it and right to it is multiplied.
        // TC : O(n) ; n = Size of input array

        for (int i=1; i<n; i++) {
            leftProduct[i] = leftProduct[i-1] * nums[i-1];
        }
        for (int i=nums.length-2; i>=0; i--) {
            rightProduct[i] = rightProduct[i+1] * nums[i+1];
        }
        for (int i=0; i<n; i++) {
            ans[i] = leftProduct[i] * rightProduct[i];
        }    
        return ans;
    }
}