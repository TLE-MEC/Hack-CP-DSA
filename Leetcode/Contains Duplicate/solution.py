class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        ## storing unique elements in a list
        unique = []
        for i in nums:
            ## if element not in the list, add it to the list
            if i not in unique:
                unique.append(i)
            ## otherwise, return True (i.e. the given list contains duplicates)
            else:
                return True

        return False