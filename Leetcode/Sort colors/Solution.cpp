//Approach:- Dutch National Flag/ Three-way partitioning
//As the name suggests partition the given array into three parts
//Make 3 variables low, mid and high
//low and mid point to a[o] whereas high points to a[nums.size()-1]
//If mid points to array element  '0' swap a[low] with a[mid] as all '0's should be in the beginning
//if mid points to '1', no swaps, just increase mid by 1
//if mid points to '2', swap a[mid] with a[high]. Decrease high by 1

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int low = 0;
        int high = nums.size()-1;
        int mid = 0;
        while(mid <= high){
            switch(nums[mid]){
                case 0: swap(nums[low++],nums[mid++]);
                    break;
                case 1: mid++;
                    break;
                case 2: swap(nums[mid],nums[high--]);
                    break;
            }
        }
    }
};

