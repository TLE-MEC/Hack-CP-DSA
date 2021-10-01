
<h2 align=center> Problem <a href="https://leetcode.com/problems/jump-game/">Link</a> </h2> 

### Given an array of non-negative integers, you are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Determine if you are able to reach the last index.

### Example 1:
### Input: [2,3,1,1,4]
### Output: true

### Explanation: From the first index, the maximum position we can jump is 2 steps and reach position 3 at max. From the second position we can jump is 3 steps to reach the end.

### Example 2: 
### Input: [3,2,1,0,4]
### Output: false

### Explanation: From the first index, the maximum position we can jump is 3 steps and reach at position 4(3 if you see array index). From the second position we can jump is 2 steps and reach at position 4 (3 if you see array index). From the third position we can jump 1 step reach at position 4(0 if you see array index). But unfortunately, from position 4, we cannot move further.
<hr>

### Java Approach: 

```
class Solution {
    public boolean canJump(int[] nums) {
        if(nums.length==1)
            return true;
        int dist = 0;
        for(int i = 0; i < nums.length; i++){
            dist=Math.max(dist, nums[i]);
            if(dist==0 && i!=nums.length-1)
                return false;
            dist--;
        }
        return true;
    }
}
```