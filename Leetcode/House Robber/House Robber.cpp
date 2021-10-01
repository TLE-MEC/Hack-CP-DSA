class Solution {
public:
    int rob(vector<int>& nums) {
        int sum[nums.size()+1];
        if(nums.size()<2){
            return nums[nums.size()-1];
        }
        bool flag =false;
        sum[0] = nums[0];
        sum[1] = max(nums[0],nums[1]);
        if(max(nums[0],nums[1])==nums[1]){
            flag = true;
        }
        for(int i = 2;i<nums.size();i++){
            if(flag == true){
                // sum[i] = nums[i] + sum[i-2];
                int m = max(sum[i-1],sum[i-2]+nums[i]);
                if(m == sum[i-1]){
                    flag = false;
                }
                sum[i] = m;
            }
            else{
                int m = max(sum[i-1]+nums[i],sum[i-2]+nums[i]);
                flag = true;
                sum[i] = m;
                
            }
        }
        return sum[nums.size()-1];
        
    }
};