class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int mid = l + (r - l) / 2; 
            // we write mid like this instead of mid = (l+r)/2 
            // as it handles integer overflow problem

            if (target == nums[mid]) //if target is at index mid
                return mid;
            
            // there exists rotation and the middle element is in the left part of the array
            if (nums[mid] > nums[r]) {
                if (target < nums[mid] && target >= nums[l])
                    //the left half
                    r = mid - 1;
                else
                    //the right half
                    l = mid + 1;
            }
            
            // there exists rotation and the middle element is in the right part of the array
            else if (nums[mid] < nums[l]) {
                if (target > nums[mid] && target <= nums[r])
                    // the right half
                    l = mid + 1;
                else
                    // the left half
                    r = mid - 1;
            }
            
            // there is no rotation and just like normal binary search
            else {
                // the left half
                if (target < nums[mid])
                    r = mid - 1;
                // the right half
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};
//-> Observations
    // we have a rotated sorted array in which the elements are rotated by k
    // we do not know the value of k 
    // elements are rotated from right to left
    // given the target, return the index of target if it is present in nums 
    // else return -1 if not in nums
    // binary search on rotated array nums


