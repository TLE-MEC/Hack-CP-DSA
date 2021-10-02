# -*- coding: utf-8 -*-
"""
Created on Mon Oct  5 2020
@author: Shrey1608
"""
# Approach : 1) using 3 loops for checking the condition(Time complexity O(n^3)| space complexity O(1))



# Solution:(Approach 1)
class Solution:
    def countGoodTriplets(self, arr: List[int], a: int, b: int, c: int) -> int:
        n=len(arr)
        count=0
        for i in range(n-2):
            for j in range(i+1,n-1):
                if (abs(arr[i] - arr[j]) > a):
                    continue
                for k in range(j+1,n):
                    if (abs(arr[j] - arr[k]) <= b and abs(arr[i] - arr[k]) <= c):
                        count+=1
        return count