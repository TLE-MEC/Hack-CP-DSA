class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int sum1=0, sum2=0;
      for(int i=0;i<nums.size();i++){
        sum1= i +sum1;               // sum1 stores the sum of first i natural numbers
        sum2 = nums[i]+sum2;        // sum2 stores the value of first i values in the array
      }
      sum1+=nums.size();
      return sum1 - sum2;           // difference of sum 1 and sum 2 gives us the missing number
    }
};
