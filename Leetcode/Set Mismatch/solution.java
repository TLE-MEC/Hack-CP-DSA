/*
Approach: Since the array contains numbers from 1 to n, so we can apply "Cyclic Sort" here.
          Let's say if a number is repeated than a number must be removed, because the size of the array is fixed.
          If the index of an element is wrong, then it is the required missing number. Also, if an element is at wrong index than it is a duplicate number.
          Hence, we get our required answer.

 */

class Solution {
    public int[] findErrorNums(int[] nums) {
        int i = 0;

        //Cyclic Sort

        while (i < nums.length) {
            int correct = nums[i] - 1; // Correct index

            //Checking if the element is at its correct index or not. If not put it at its correct index. i.e., Sorting in increasing order.
            if (nums[i] != nums[correct]) {
                int temp = nums[i];
                nums[i] = nums[correct];
                nums[correct] = temp;
            } else { // if the element is already at its correct index.
                i++;
            }
        }

        // Searching for the first missing number, and the missing number is also a duplicate number.
        for (int j = 0; j < nums.length; j++) {
            if (nums[j] != j + 1) {
                return new int[]{nums[j], j + 1}; // First element is missing number and the second element is duplicate number.
            }
        }
        return new int[]{-1, -1}; // If nothing is wrong. i.e., there is no duplicate and missing number.
    }
}
