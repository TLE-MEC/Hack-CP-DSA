class Solution {
    public int searchInsert(int[] nums, int target) {
	
        // determine if array has a target inside
		
        for (int i = 0; i < nums.length; i++){
            if(nums[i]==target){
                return i; 
            }
        }
        
        //at this point target is not inside of an array then
        // check if target is bigger that last elemenet of an array
        // if the target is bigger then it should be placed in nums.length position
		
        if(target > nums[(nums.length-1)])
                    return nums.length;
        
        else
            // if target is not bigger than the last element of an array
            // determine where it should be located by comparing each element
            // is less than of target or not. If an element is bigger than the target
            //then the target should be placed in the element's index
			
            for (int i = 0; i < nums.length; i++){
            if(nums[i]<target){
                continue; 
            }else{
                return i;
            }
        }
        
        return -1;
    }
}