class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        low, mid, high = 0, 0, len(nums) - 1
        
        while low <= high:            
            # Calculate middle index
            mid = (high + low) // 2
            
            # If the number was found
            if nums[mid] == target:
                return mid
            
            # Middle is smaller, use right side
            elif nums[mid] < target:
                low = mid + 1
                
            # Middle is larger, use left side
            else:
                high = mid - 1
        
        # Insertion case
        if nums[mid] > target:
            return mid
        else:
            return mid + 1