class Solution {
        public int[] twoSum(int[] nums, int target) 
        {
            int c;
            for (int i = 0; i<nums.length; i++) 
            {
                c = target - nums[i];
                for (int j = 0; j<nums.length; j++) 
                {
                    if (i ==  j) { continue; }
                    if (nums[j] == c) {
                        return new int[] {i, j};
                    }
                }
            }
            return new int[] {0, 0};
        }
    }