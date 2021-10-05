/*
We are going to use Binary Search to solve this problem with little bit of modification
A special input'StartingIndex' will also be used with when value of true will try to find the elftmost element and vice a versa.
As there is a possibility that, we are at the leftmost or the rightmost element, we will also be storing the index as an answer. 
*/



int Binary_Search(vector<int> & nums, int start, int end, int target, bool StartingIndex,int answer)
{
    if (start <= end)
    {
        int mid = start + (end - start)/2;
        if (nums[mid] > target)
        {
            return Binary_Search (nums,start,mid - 1,target,StartingIndex,answer);
        }
        else if (nums[mid] < target)
        {
            return Binary_Search(nums,mid +1,end,target,StartingIndex,answer);
        }
        else
        {
            answer = mid;
            if (StartingIndex)
            {
                return Binary_Search (nums,start,mid - 1,target,StartingIndex,answer);
            }
            else
            {
                return Binary_Search(nums,mid + 1,end,target, StartingIndex,answer);
            }
        }
    }
    return answer;
}



class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2);
        int answer = -1;
        result[0] = Binary_Search(nums,0,nums.size() - 1,target,true,answer);
        if (result[0] != -1)
        {
            result[1] = Binary_Search(nums,0,nums.size()-1,target,false,answer);   
        }
        else
        {
            result[1] = -1;
        }
        return result;
    }
};
