class Solution {
    public static void sortColors(int[] nums) {
        int second=nums.length, zero=-1;
            for (int i=0; i<second; i++) {
                while (nums[i]==2 && i<second) swap(nums,i, --second);
                while (nums[i]==0 && i>zero) swap(nums,i, ++zero);
            }
    }
    static void swap(int[] arr, int first, int second) {
        int temp = arr[first];
        arr[first] = arr[second];
        arr[second] = temp;
    }
}