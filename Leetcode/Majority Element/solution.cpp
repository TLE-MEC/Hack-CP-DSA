// ##TimeComplexity: Since we travel vector only once, thus time taken will be O(N).

// ##SpaceComplexity: Since no extra data structure is used, so space Complexity will be O(1). 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0,elem=0,size=nums.size();
        for(int i=0;i<size;i++)
        {
            if(c==0)
            elem=nums[i];
            if(nums[i]==elem)
            c++;
            else
            c--;
        }
        c=0;
        for(int i=0;i<size;i++)
        if(nums[i]==elem)
        c++;
        if(c>floor(size/2))
        return elem;
        else
        return -1;
    }
};