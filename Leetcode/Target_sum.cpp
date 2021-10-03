class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
        }
        // check if target value is greater then sum of vector elements then answer will be zero always
        // also check if sum-target is odd then answer will be zero always
        if(target>sum || (sum-target)%2!=0 )
        {
            return 0;
        }
        // if target is zero then answer will be zero
        if(sum%2!=0 && target==0)
        {
            return 0;
        }
        int nsum=(sum+target)/2;
        // in case if we have negative target then we have to make it positive to find actual answer
        if(nsum<0)
        {
            nsum=-1*nsum;
        }
        // creating 2d matrix to store answer of  repeative recursive call
        int a[nums.size()+1][nsum+1];
        // intialising matrix with recursive function base value
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
        // start filling matrix using recursive method memorisation
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
        // return final answer
        return a[nums.size()][nsum];
    }
};
