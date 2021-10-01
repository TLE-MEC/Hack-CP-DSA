//Explaination: At each iteration we have to check the maximum index we can reach from the current index we are at and update it.
// TC : O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;//Let this be the maximum we can reach.
        
        for(int i = 0; i < nums.size(); i++) {
            //If we can reach this index, then update the maxReach possible.
            if(i <= maxReach) {
                maxReach = max(maxReach, i + nums[i]); //Updating the maxReach.
            }
        }
        
        return maxReach >= nums.size() - 1; // if we are able to reach the end or not.(since we have to return boolean)
    }
};