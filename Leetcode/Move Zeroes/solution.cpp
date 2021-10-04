void moveZeroes(vector<int>& nums) {
        if(nums.size() < 2)    //There is no need to move zeroes if the size is 1 or 0
            return;
        int index = 0;  //Index variable used to populate the array with non-zero values
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                nums[index++] = nums[i];   //Non-zero values are copied to the nums[index] and index is incremented
            }
        }
        //The rest of the array can be now filled with zeroes
        for(int i = index; i < nums.size(); i++){
            nums[i] = 0;    
        }
}
