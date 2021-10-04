class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());                             //Sorting the array
        for (int i = nums.size()-1; i >= 2; i--)
        {
            if (nums[i - 1] + nums[i - 2] > nums[i])                //Checking whether the property of sides of triangle is valid for the set of numbers 
            {
                return nums[i] + nums[i - 1] + nums[i - 2];         //Calculating perimeter
            }
        }
        return 0;
    }
};