/* Upper version of question 2 sum, and 3 sum, the basic approach of using two pointer approach for finding two numbers whose sum up matches the target,
The problem is first converted from four sum to three sum and then from three sum to two sum.
*/


vector<vector<int>> TwoPointerApproach (vector<int>& nums,int index, int target,int prev_index)
{
    /* setting left index+1 jut makes it ensures that the elements are not repeated again and again, making a check that we
    can only look forward very smart thing to do*/
    int left = index+1;
    int right = nums.size()-1;
    vector<int> answer{INT_MIN,0,0,0}; 
    vector<vector<int>> answer_final;
    while (left<right)
    {
        bool flag = true;
        int sum  = nums[left] + nums[right];
        if (sum == target)
        {
            answer[0] = nums[prev_index];
            answer[1] = nums[index];
            answer[2] = nums[left];
            answer[3] = nums[right];
            sort(answer.begin(),answer.end());
            answer_final.push_back(answer);
            left++;
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
    }
    answer_final = convertToSet(answer_final);
    return answer_final;
}

vector<vector<int>> threeSum(vector<int>& nums,int index,int target)
{
        vector<vector<int>> answer_final;
        for (int i = index+1;i < nums.size();i++)
        {
            vector<vector<int>> answer;
            answer = TwoPointerApproach(nums,i,target - nums[i],index);
            for (int i = 0; i < answer.size();i++)
            {
                answer_final.push_back(answer[i]);
            }
            while((i < (nums.size()-1)) && nums[i] == nums[i+1])
            {
                i++;
            }
        }
        return answer_final;
}

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> answer_final;
        for (int i = 0;i < nums.size();i++)
        {
            vector<vector<int>> answer;
            answer = threeSum(nums,i,target - nums[i]);
            for (int i = 0; i < answer.size();i++)
            {
                answer_final.push_back(answer[i]);
            }
            while((i < (nums.size()-1)) && nums[i] == nums[i+1])
            {
                i++;
            }
        }
        return answer_final;
    }
};
