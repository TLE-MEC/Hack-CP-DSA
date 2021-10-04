//This is a DP(dynamic programming) based solution.
//Time Complexity => O(n*n) ; Space Complexity => O(n)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        // for each position in the array, we calculate the minimum steps to get to that position
        // vector min_for_each stores these minimum steps for each position
        vector<int> min_for_each(n, INT_MAX-1); // Initialize with INT_MAX so we can replace it with a minima
        dp[0] = 0; // first position is 0 steps away
        for(int i = 0; i < n; i++){ // for each position 'i' in the array
            for(int j = 1; j < min(n - i, 1+nums[i]); j++){ //go to each position 'j' that is reachable form 'i'
                //the steps stored is either already minimum or it can be reached with 1 addition step from 'i'
                min_for_each[i + j] = min(min_for_each[i + j], min_for_each[i] + 1);
            }
        }
        //return the min steps for last position
        return min_for_each.back();
    }
};