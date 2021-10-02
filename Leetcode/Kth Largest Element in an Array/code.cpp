class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        for (auto i : nums)
        {
            cout << i << " ";
        }
        cout << endl;
        return nums[nums.size() - k];
    }
};