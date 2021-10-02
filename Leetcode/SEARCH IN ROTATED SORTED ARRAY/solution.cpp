 int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() -1;
        
        while (lo <= hi)
        {
            int mid = (lo + hi) >> 1;// mid element of array
            if (nums[mid] == target)// if mid element of array eqaul to target
                return mid;          // return mid
            if (nums[lo] <= nums[mid])// this check the right part is sorted or not 
            {
                if(target >= nums[lo] && target <= nums[mid])// if true it's in right part
                    hi = mid -1;
                else                    // element is in the left part
                    lo = mid + 1;
            }
            
            else{
                if (target >= nums[mid] && target <= nums[hi])//if true element is in left part
                    lo = mid +1;
                else                       // element in right part
                    hi = mid -1;
            }
        }
        return -1;
    }