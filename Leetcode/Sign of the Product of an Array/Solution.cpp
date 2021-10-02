class Solution
{
public:
    int arraySign(vector<int> &nums)
    {
        int n = nums.size();
        int negativeCntr;
        for (int i = 0; i < n; i++)                 //Checking for negative numbers and storing the number in the counter variable
        {
            if (nums[i] < 0)                        //Checking whether a number is negative
                negativeCntr++;
            else if (nums[i] == 0)
                return 0;
        }
        if (negativeCntr % 2 == 0)                  //Checking whether number of negative numbers are odd or even
            return 1;                               //Product of even number of negative numbers is positive
        return -1;                                  //Product of odd number of negative numbers is negative
    }
};