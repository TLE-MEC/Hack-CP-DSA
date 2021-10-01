class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        
        //Arraylist for storing result
        ArrayList<List<Integer>> res = new ArrayList<List<Integer>>();
        //base case
        if(nums == null || nums.length == 0)
            return res;
        //sorting the given arrray
        Arrays.sort(nums);
        int n = nums.length;
        for(int i = 0; i<nums.length; i++) //a pointer at an element
        {
            for(int j = i+1; j<nums.length; j++)  //popinter at an element immediate next of previous element
            {
                int start = j+1; //a pointer at j+1
                int end = n-1;   //a pointer at last to calculate 2sum bascially 
                int tempTarget = target - nums[i] - nums[j];
                
                //calculating 2sum
                while(start<end)
                {
                    int twoSum = nums[start] + nums[end];
                    
                    if(tempTarget > twoSum)
                        start++;
                    
                    else if(tempTarget < twoSum) 
                        end--;
                    
                    else
                    {
                        //if the sum is equal then add it to the list by making a list
                        ArrayList<Integer> quad = new ArrayList<>();
                        quad.add(nums[i]);
                        quad.add(nums[j]);
                        quad.add(nums[start]);
                        quad.add(nums[end]);  
                        res.add(quad); //adding to the list
                        
                        //this checks if the element is repeating element
                        while(start < end && nums[start] == quad.get(2)) 
                        {
                            start++;
                        }
                        //this checks if the element is repeating element
                        while(start < end && nums[end] == quad.get(3)) 
                        {
                            end--;
                        }
                    }
                }
                //this checks if the element is repeating element
                while(j+1 < n && nums[j+1] == nums[j]) j++;                   
            } 
            //this checks if the element is repeating element
            while(i+1 <n && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
}
