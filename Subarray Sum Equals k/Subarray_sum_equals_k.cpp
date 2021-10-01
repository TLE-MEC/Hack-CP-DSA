class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i]; //stores current sum
            count += m[sum - k]; //checks if sum-k is also in the map then counts it also
            m[sum]++; //marking the possible sums as 1
        }
        return count; //returning the count 
    }
};

//  int subarraySum(vector<int>& nums, int k) {
//          // TC: O(N^3) & SC: O(1) - TLE
//         int len=nums.size(), count=0;

//         for(int i=0;i<len;i++){ 
//             for(int j=i;j<len;j++){ 
//                 int sum=0;
//                 for(int k=i;k<=j;k++){ 
//                    sum+=nums[k]; 
//                 }
//                 if(sum==k) s
//                     count++;
//             }
//         }
//         return count;
//     }