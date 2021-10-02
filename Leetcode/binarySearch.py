# THE PROBLEM STATEMENT IS TO CHECK WHETHER THEB TARGET ELEMENT IS PRESENT IN THE GIVEN ARRAY. IF PRESENT RETURN THE INDEX IN WHICH IT RESIDES IN ELSE RETURN -1.

# MY APPROACH IS TO DO A RECURSIVE BINARY SEARCH, SINCE THE GIVEN ARRAY IS IN THE SORTED FORMAT. SO, FIRST WE WILL CHECK WHETHER THE MIDDLE ELEMENT IS EQUAL TO THE
# TARGET, IF IT IS RETURN THE INDEX, ELSE WE WILL CHECK WHETHER THE MIDDLE ELEMENT IS GREATER THAN THE TARGET, IF IT IS CHECK THE LEFT SUBARRAY,
# ELSE CHECK THE RIGHT SUBARRAY. DO THIS IN A RECURSIVE MANNER TO FIND THE POSITION OF THE TARGET IF PRESENT ELSE IT WILL RETURN -1.

class Solution:
    def binarySearch(self,arr,start,end,target):
        if(start <= end):
            # FINDING THE MIDDLE ELEMENT.
            mid = start+((end-start)//2)
            
            # CHECKING WHETHER THE MIDDLE ELEMENT IS EQUAL TO THE TARGET.
            if(arr[mid] == target):
                return mid
            
            elif(arr[mid] < target):
                return self.binarySearch(arr,mid+1,end,target)
            
            elif(arr[mid] > target):
                return self.binarySearch(arr,start,mid-1,target)
                
        return -1 
            
    def search(self, nums: List[int], target: int) -> int:
        return self.binarySearch(nums,0,len(nums)-1,target)

# TIME COMPLEXITY : O(LOG N)
# SPACE COMPLEXITY : O(N) BECAUSE THE FUNCTION CALLS ARE STORED IN THE STACK, HENCE THE SPACE COMPLEXITY WOULD BECOME O(N)
