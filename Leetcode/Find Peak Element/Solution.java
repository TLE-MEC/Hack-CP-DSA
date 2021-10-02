// Applying Binary search
// Time Complexity : O (log n) ; n is the size of input array
class Solution {
    public int findPeakElement(int[] nums) {
        if (nums.length == 1)
            return 0;
        int l = 0, r = nums.length - 1, mid = 0;

        while (l <= r) {
            mid = (l + r) / 2;

            if (mid != 0 && mid != nums.length - 1) {
                if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid])
                    return mid;
                else if (nums[mid - 1] > nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            } else if (mid == 0) {
                if (nums[mid + 1] < nums[mid])
                    return mid;
                else
                    l = mid + 1;
            } else if (mid == nums.length - 1) {
                if (nums[mid - 1] < nums[mid])
                    return mid;
                else
                    r = mid - 1;
            }

        }
        return mid;
    }
}