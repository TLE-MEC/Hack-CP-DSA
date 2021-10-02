class Solution
{
public:
    int target;

    //Approach: Bit Masking, ith bit of status denotes if the ith element is already taken in some subset formation

    // t is the total target we want to achieve, if we take num[i], then we will have t - nums[i] to make, and if t == 0, we have formed a subset
    bool calc(vector<int> &nums, int k, int i, int t, int status)
    {
        //If k==0 , all the subsets have been formed
        if (k == 0)
            return true;
        //If t==0, we have formed one subset, k-1 subsets will remain to form
        if (t == 0)
            return calc(nums, k - 1, 0, target, status);
        if (i == nums.size() || t < 0)
            return false;

        //If ith element is already taken, then no option, we have to form the target from (i+1)th element onward
        if ((status & (1 << i)) != 0)
            return calc(nums, k, i + 1, t, status);
        //If not so, we can either use the current element, int that case target changes to t - nums[i], or we don't take the current element
        //In that case, target t remains the same
        return calc(nums, k, i + 1, t - nums[i], status ^ (1 << i)) || calc(nums, k, i + 1, t, status);
    }

    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        target = accumulate(nums.begin(), nums.end(), 0);
        if (target % k != 0)
            return false;
        //Target will be total sum divided by total number of susbsets.
        target /= k;
        return calc(nums, k, 0, target, 0);
    }
};