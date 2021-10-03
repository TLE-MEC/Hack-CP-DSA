class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        
        vector<bool> ans;
        // This is a Brute Force Approach - O(n ^ 2 log n) approach
        int n = nums.size();
        
        // We have to find out whether the given sequence is Arithmetic Progression or not
        for(int i=0; i<l.size(); i++)
        {
            vector<int> temp;
            int left = l[i];
            int right = r[i];
            
            // We will go through each and every element between l and r 
            for(int i=left; i<=right; i++)
                temp.push_back(nums[i]);
            
            // We are sorting the temporary array for rearranging basically
            sort(temp.begin(), temp.end());
            
            if(temp.size() == 1)
                ans.push_back(false);
            else if(temp.size() == 2)
                ans.push_back(true);
            else
            {
                // f is a flag variable which checks that whether our condition breaks somewhere or not for AP
                int diff = temp[1] - temp[0], f = 0;
                for(int i=2; i<temp.size(); i++)
                {
                     int t = temp[i] - temp[i-1];
                     if(t == diff)
                         continue;
                    else
                        f = 1;
                }
                if(f == 0)
                    ans.push_back(true);
                else
                    ans.push_back(false);
            }
        }
        
        // returning the boolean array of answers
        return ans;
    }
};