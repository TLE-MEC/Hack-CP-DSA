// Number of Longest Increasing Subsequence
// link (https://leetcode.com/problems/number-of-longest-increasing-subsequence/)

//Explaination :  create two vectors lis and count. Lis keep track of Longest increasing subsequence .
//                count will track of number of increasing subsequence till i. find maximimum element from lis.
//                make result varialble for final answer. traverse lis . if lis[i]== longest means till i there islongest.
//                so add result +=count[i]. count will contain number of increasing subsequence till i



class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)return n;
        vector<int>lis(n,1),count(n,1);
        
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(nums[i]<nums[j]){
                    if(lis[i]>=lis[j]){
                        lis[j]=lis[i]+1;
                        count[j]=count[i];
                    }
                    else if(lis[j]==lis[i]+1){
                        count[j]+=count[i];
                        
                    }
                }
            }
        }
        int longest = *max_element(lis.begin(),lis.end());
        int result=0;
        for(int i=0;i<n;i++){
            if(lis[i]==longest)
                result+=count[i];
        }
        return result;
    }
};