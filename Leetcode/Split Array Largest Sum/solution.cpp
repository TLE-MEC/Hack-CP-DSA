/** Approach: First calculate the range of the sum and start binary search in this range return when start is equal to end. **/


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {

       // for calculating range of our sums
        int start = INT_MIN, end = 0;
        for(int i = 0; i < nums.size(); i++){
            start = max(start, nums[i]);
            end += nums[i];
        }
        // start binary search in the range
        int mid;
        while(end > start){

            mid = start + (end - start)/2;
            int sum = 0, pieces = 1;
            for(int i = 0; i < nums.size(); i++){
                if(sum + nums[i] > mid){
                    sum = nums[i];
                    pieces++;
                }
                else{
                    sum += nums[i];
                }
            }
            if(pieces <= m){
                end = mid;
            }
            else{
                start = mid+1;
            }
    
        }
        return end; // when start and end are equal
    }
};