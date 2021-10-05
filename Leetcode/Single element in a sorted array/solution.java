class Solution {
    /*
    Approach: Here we have to find the element which appears exactly once, and question is asking for an algorithm which runs in O(log n) and O(1) space. So, we can use Logical operator "XOR" because
        XOR gives 0 for same value, and 1 for different value, and when we XOR the entire array we will be remaining with the element which we need because all the duplicate elements XORed by themselves.
        Also, the array is already sorted, so it makes our problem easier, and then its space complexity is O(1), which is required. And the elements are in the range of [0, 10^5], so don't need to worried
        about negative numbers.
     */

    public int singleNonDuplicate(int[] nums) {
        int ans = 0;
        for (int element : nums) // For each element in array
            ans ^= element; // Just XOR it
        return ans;
    }
}

