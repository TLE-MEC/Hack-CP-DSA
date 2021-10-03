//We partition the given array into three parts
//Make 3 variables zero and second
//zero=-1 whereas second=nums.length
//run for loop from i=0 till i<second
//If nums[i]==2 && i<second
//      decrease second by one
//      swap nums[i] with nums[second] as all 2s must be placed at last
//If nums[i]==0 && i>zero
//      increase zero by one
//      swap nums[i] with nums[zero] as all 0s must be placed at the start

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
