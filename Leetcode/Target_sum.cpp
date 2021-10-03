class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
        }
        if(target>sum || (sum-target)%2!=0 )
        {
            return 0;
        }
  
        if(sum%2!=0 && target==0)
        {
            return 0;
        }
        int nsum=(sum+target)/2;
        if(nsum<0)
        {
            nsum=-1*nsum;
        }
        int a[nums.size()+1][nsum+1];
        for(int i=0;i<(nums.size()+1);i++)
        {
            for(int j=0;j<nsum+1;j++)
            {
                if(i==0)
                {
                    a[i][j]=0;
                }
                if(j==0)
                {
                    a[i][j]=1;
                }
            }
        }
        for(int i=1;i<(nums.size()+1);i++)
        {
            for(int j=0;j<nsum+1;j++)
            {
                if(nums[i-1]<=j)
                {
                    a[i][j]=a[i-1][j]+a[i-1][j-nums[i-1]];
                }
                else
                {
                    a[i][j]=a[i-1][j];
                }
            }
        }
        return a[nums.size()][nsum];
    }
};
