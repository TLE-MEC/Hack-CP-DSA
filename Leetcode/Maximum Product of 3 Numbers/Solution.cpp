class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());                                       //Sorting the given vector

        int n = nums.size();
        
        int product1 = nums[0] * nums[1] * nums[n - 1];                       //Calculating maximum of 1 set of numbers
        int product2 = nums[n - 1] * nums[n - 2] * nums[n - 3];               //Calculating maximum 
        
        return max(product1, product2);                                       //Returning maximum out of those two sets
    }
};