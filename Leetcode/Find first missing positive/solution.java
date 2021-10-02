/*
Approach: Since we are asked to implement an algorithm which runs in O(n) time and O(1) space, also given an unsorted array. We can use cyclic sort here, because its time complexity is O(n) and uses O(1) space.
          Also there is no need to worried about negative numbers, simply ignore them. Start searcing from 0th index the first index that we find, that is not having the required number at that index, then that is our answer.
	      Also if all the elements are at their correct indices than length of array is our answer.
*/


class Solution {
    public int firstMissingPositive(int[] nums) {
        int i = 0;
        while (i < nums.length) {
            int correct = nums[i] - 1; // Correct Index of ith element.

            if (nums[i] > 0 && nums[i] <= nums.length && nums[i] != nums[correct]) // Ignoring the negative as well as the numbers greater than then the length of given array.
            {
                // Putting the ith element at its correct index.
                int temp = nums[i];
                nums[i] = nums[correct];
                nums[correct] = temp;
            } else { // If the element in its sorted version is at its correct index.
                i++;
            }
        }

        for (int index = 0; index < nums.length; index++) // Searching for the first positive number.
        {
            if (nums[index] != index + 1)
                return index + 1;
        }
        return nums.length + 1; // If all elements at its correct index then the length of array is answer.
    }
}
