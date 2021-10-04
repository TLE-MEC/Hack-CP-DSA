/*
Approach : Dynamic Programming	

1. Checking whether the sum is odd or even
2. if it is odd, then the array cannot be partitioned into two subsets.
3. If it is even, then
	3.1 Dividing the sum by 2
	3.2 Finding the subset with sum equal to (sum/2) because if we find a subset with half of the sum then the other subset will automatically have a sum of (sum/2)

Time Complexity: O(n*s)  => n = size of the array , s = (total sum)/2
Space Complexity: O(n^2)

*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        bool ans;
        for(int i=0;i<nums.size();i++)
            sum= sum + nums[i];
        
        if(sum%2 != 0)
            return false;
        else if(sum%2 == 0)
        {
            int s=sum/2;
            bool v[n+1][s+1];
            for(int j=0;j<=n;j++)
            {
                for(int k=0;k<=s;k++)
                {
                    if(k==0 && j==0)
                        v[j][k]=true;
                    else if(j==0)
                        v[j][k]=false;
                    else if(k==0)
                        v[j][k]=true;
                    else if(nums[j-1]<=k)
                        v[j][k]=(v[j-1][k-nums[j-1]] || v[j-1][k]);
                    else 
                        v[j][k]=v[j-1][k];
                }
            }
            ans= v[n][s]; 
        }
        return ans; 
    } 
};