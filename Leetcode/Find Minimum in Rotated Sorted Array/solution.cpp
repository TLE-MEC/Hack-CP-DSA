//Space Complexity O(1)
//Time Complexity O(log2 n)

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, mid, r = nums.size() - 1;
        //checking for lenght = 1
        if (r == 0)
            return nums[0];

        //Dividing in form of Binary
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (nums[l] < nums[r]) //Already done
                return nums[l];
            else if (nums[mid] > nums[r]) //Updating the middle term
                l = mid + 1;
            else
                r = mid;
        }
        return nums[l];
    }
};