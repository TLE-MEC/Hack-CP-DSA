/*

Approach - Stack

Space Complexity: O(n)
Time Complexity: O(n)

*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n);
        stack<int> s;
        
        // Pushing the elements of nums into the stack. 
        // If nums[i] is greater than top then remove all the elements from the stack that are smaller than nums[i]
        for(int i=2*n-1;i>=0;i--)
        {
            while(!s.empty() && nums[i%n]>=s.top())
                s.pop();
            if(i<n)
            {
                if(s.empty()) // If stack is empty, then this the greater number in that array
                    v[i]=-1;
                else
                    v[i]=s.top(); 
            }
            s.push(nums[i%n]);
        }
        return v;
        
    }
};