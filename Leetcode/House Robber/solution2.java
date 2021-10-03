class Solution {
    // we have to rob houses such that we got max amount of money and we cant rob two adjesunt houses.


    public int rob(int[] nums) {
        if (nums.length == 0) // if length is equal to 0 then max amount is 0 that can be robbed.
            return 0;
        int inc = nums[0];  // if we rob first house then total amount we can rob is
        int exc = 0;// if we rob second house then total amount we can rob is

        for (int i = 1; i < nums.length; i++) {
            int tinc = inc; //temp including curr house
            int texc = exc; //temp excluding curr house

            exc = Math.max(texc, tinc);  // max amount rob excluding current house can be max of last index including and excluding.
            inc = texc + nums[i]; // max amount rob including current house can be sum of last index including and amount at current index.

        }
        // ans will be max of both.
        return Math.max(inc, exc);
    }
}