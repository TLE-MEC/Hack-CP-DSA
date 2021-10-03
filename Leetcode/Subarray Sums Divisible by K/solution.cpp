/** Approach: Intialize a map which stores remainder(element divided by K)as a key and keep a counter which counts all the subarrays which have same remainder. 
For negative numbers we need to add K to the remainder.**/


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0, total = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            total += nums[i];
            int rem = total%k;
             if(rem < 0){
                 rem = k + rem;
             }   
            res += m[rem]; 
            m[rem]++;
        }
        
        return res;
    }
    
};