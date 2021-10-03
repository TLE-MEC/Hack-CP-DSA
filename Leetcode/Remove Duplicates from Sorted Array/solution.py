class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        # If array is empty
        if len(nums) == 0:
            return 0
        # Two Pointer Solution
        # j is slow runner, i is fast runner
        j = 0;
        for i in range(1, len(nums)):
        # If they are unique, change the array and increment both
            if nums [i] != nums[j]:
                j += 1
                nums[j] = nums[i]
        # Return the slow runner + 1 for length
        return j + 1
    
    # Testing
def main():
    x = Solution()
    y = x.removeDuplicates([1,1,1,1,2,3,3])
    print y

main()
