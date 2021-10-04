// Link to problem : https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int c=0;	//count is initialized to zero
//Run 2 loop to check if the concat value of 2element is equal to the target
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
//if both the loop points to same position then skip the iteration
                if(j==i)
                    continue;
// check if the concat value is same as target or not if true the increase the count
                if(nums[i]+nums[j]==target)
                    c++;
            }
        }
// return the number of times the concat value is same as target
	return c;
    }
};