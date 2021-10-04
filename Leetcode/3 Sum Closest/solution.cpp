/*
This question will be better solved after you solve the question 3 Sum, where you need to find the right combination.
The solution uses the same approach, with a little bit of modification
we will keep a track of the closest difference number for ech of the number and then find the lostwest and return it.
*/

int TwoPointerApproach (vector<int>& nums,int index, int target)
{
    /* setting left index+1 jut makes it ensures that the elements are not repeated again and again, making a check that we
    can only look forward*/
    int left = index+1;
    int right = nums.size()-1;
    int Min = INT_MAX;
    int Required_Sum = INT_MAX;
    while (left<right)
    {
        int sum  = nums[left] + nums[right]+ nums[index];
        if (Min > abs(sum-target))
        {
            Min = abs(sum-target);
            Required_Sum = sum;
        }
        
        if (sum < target)
        {
            while ( left+1 < nums.size() && nums[left] == nums[left+1])
            {
                left++;
            }  
            left++;
        }
        else if (sum > target)
        {
            while (right-1 >= 0 && nums[right] == nums[right-1])
            {
             right--;   
            }
            right--;
        }
        else
        {
            left++;
        }
    }
    return Required_Sum;
}


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int Min = INT_MAX;
        int answer,Required_Sum;
        for (int i = 0;i < nums.size();i++)
        {
            
            answer = TwoPointerApproach(nums,i,target);
            if (answer == target)
            {
                return answer;
            }
            else if (answer != INT_MAX)
            {
                if (Min > abs(answer-target))
                {
                    Min = abs(answer-target);
                    Required_Sum = answer;
                }
            }
            while((i < (nums.size()-1)) && nums[i] == nums[i+1])
            {
                i++;
            }
        }
        return Required_Sum;
    }
};
