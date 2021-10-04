// XOR Approach:
// Initialize ans to 0
// Iterate over the array and take XOR of the current element with ans
// Use of 2 properties (1) x ^ x = 0  (2) x ^ 0 = x
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int num: nums) {
            ans = ans ^ num;
        }
        return ans;
    }
};