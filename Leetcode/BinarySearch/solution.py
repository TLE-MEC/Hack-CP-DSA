# RECURSIVE BINARY SEARCH.

class Solution:
    def binarySearch(self,arr,start,end,target):
        if(start <= end):
            # FINDING THE MIDDLE ELEMENT.
            mid = start+((end-start)//2)
            
            # CHECKING WHETHER THE MIDDLE ELEMENT IS EQUAL TO THE TARGET.
            if(arr[mid] == target):
                return mid
            # CHECKING WHETHER THE MIDDLE ELEMENT IS LESSER THAN THE TARGET.
            elif(arr[mid] < target):
                return self.binarySearch(arr,mid+1,end,target)
            # CHECKING WHETHER THE MIDDLE ELEMENT IS GREATER THAN THE TARGET.
            elif(arr[mid] > target):
                return self.binarySearch(arr,start,mid-1,target)
                
        return -1 
            
    def search(self, nums: List[int], target: int) -> int:
        return self.binarySearch(nums,0,len(nums)-1,target)
