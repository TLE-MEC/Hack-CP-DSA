class Solution {
    /*
    There are many ways to solve this problem, but I'm solving it via recursive approach.
    Approach: This question is saying, how can we reduce a number to zero.
                We have to check, if the current number is even, we have to divide it by 2, otherwise, we have to subtract 1 from it. We have to do this till number reduces to zero.
                So, we can check number and do accordingly, and keep counting our steps in reducing the number to zero.
     */

    public int numberOfSteps(int num) {
        // This function will perform some operation and return answer.
        return helper(num, 0);
    }

    private int helper(int num, int steps) {
        if (num == 0) { // Base Condition or if given number is already 0, then we don't have to do anything, hence 0 steps required to do so.
            return steps;
        }

        if (num % 2 == 0) // If given number is even, since we are doing something, which is also a step, that's why we have to increase our steps.
            return helper(num / 2, steps + 1);

        return helper(num - 1, steps + 1); // If given number is not even, here we are also doing something, which is also a step, that's why we have to increase our steps.
    }
}
