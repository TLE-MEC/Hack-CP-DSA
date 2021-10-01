"""
1. Find the 2 number which sums to the target values
Step 1:
    - Save the (target-arra[i]) to a dict with its index as value ---> (target - arr[i]) : index.
Step 2:
    - Iterate to the array.
Step 3: 
    - If the value present in the dict --> return the value and the array value index.
"""
class Solution:
    def twoSum(self, nums, target):
        d = {}
        for index , l in enumerate(nums):
            d[(target - l)] = index
        print(d)
        for index , l in enumerate(nums):
            if l in d and index != d[l]:
                
                
                return [index , d[l]]