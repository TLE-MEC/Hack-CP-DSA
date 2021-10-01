#include <algorithm>
class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int n = nums.size();                      //Storing size of vector

        sort(nums.begin(), nums.end());           //Sorting the vector

        int gcd = __gcd(nums[0], nums[n - 1]);    //Finding GCD of largest and smallest number

        return gcd;
    }
};