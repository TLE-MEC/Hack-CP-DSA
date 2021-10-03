/*time complexity-O(n*2^n) , space complexity(n*2^n)*/
/*1-total number of subsets will be-(2^n)(where n is array size)
2-upper bound of a k bit number will be-(2^k)-1
3-the binary representation of numbers from 1 to 2^k -1 gives permutations of set bits in k bit number.
4-so we can iterate from 1 to 2^n-1 and each iteraton we can find which permutation it represents.*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int>t;
        /*for empty subset*/
        ans.push_back(t);
        /*step-4*/
        for(int i=1;i<=(1<<n)-1;i++)
        {
            int nm=i;
            /*stores the subset of ith permutation*/
            vector<int>subi;
            /*check which bits are set*/
            /*this section gives the rightmost set bit and then unset it.*/
            while(nm)
            {
            subi.push_back(nums[__builtin_ctz(nm)]);
            nm-=nm&(-nm);
            }
            ans.push_back(subi);
        }
       
        return ans;
    }
};