class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size(), ans=0;             //defining variables
        sort(nums.begin(),nums.end());        // sorted vector for easily finding repeated number
          for (int i=0;i<n;i++){
                    if(nums[i]==nums[i+1]) {ans=nums[i];
                                                  break;}   // breaking loop when conditon fulfilled
          }
        return ans;    // returning ans
    }
};
