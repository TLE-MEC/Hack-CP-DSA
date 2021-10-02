/*
This question is very similar to Maximum Subarray Problem, but with one key difference.
Here even if the current product becomes negative, we cannot discard the subarray as we might encounter another negative number in the remaining part of the array.
For eg:
in the array [1,-2,2,-1], the maximum product in the subarray is 4. This comes from the fact that two negative numbers when multiplied give positive number.

Approach:
    - Due to the above fact, we need to maintain the current maximum and current minimum while traversing through the array.
      The current minimum (if negative) when multiplied with another negative might give a positive number.   
    - the final result is the maximum value from all the current maximum calculated. 

Time Complexity:
    - since all elements are traversed only once, time complexity - O(n), where n = number of elements in the array.

Space complexity
    - since no extra space has been used, space complexity - O(1).
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==1)
            return nums[0];
        int res  = nums[0];// this will contain the final result 
        int currmax = 1,  currmin = 1; // as initial product cannot be 0
        for(int i:nums)
        {
            int temp = currmax*i;// create a copy of currmax*i as it changes in the next step
            currmax = std::max(currmax*i,std::max(currmin*i,i)); // calculating currmax
            currmin = std::min(temp,std::min(currmin*i,i));// calculating currmin
            res = std::max(res,currmax);// updating res

        }
        return res;
    }
};