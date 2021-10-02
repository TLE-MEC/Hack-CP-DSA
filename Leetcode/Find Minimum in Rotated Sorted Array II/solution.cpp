class Solution {
public:
    int findMin(vector<int>& nums) {
                int low = 0;
        int high = nums.size()-1;
        
        while(low < high)
        {
            int mid = (high-low)/2 + low; //find the middle element in the                                              given array    
            
            if(nums[high] > nums[mid])
            {
                high = mid;
                // if(nums[high]>nums[mid]) means the elements from nums[mid] to nums[high] are in sorted order. We can eleminate the elements from index mid+1 to high as they can't be the minimum elements.
            
            }else if(nums[high] < nums[mid])
            {
                low = mid+1;
                // or else the minimum is present in the second half . Apply binary search in the second half.
            }
            else
            {
                high--;
            // if(nums[high]==nums[mid]) , decrement high and find again apply Binary Search
            }
        }
        
        return nums[low];
        // high and low at last point to the same element in the array , so return nums[low] or nums[high]
    }
};

