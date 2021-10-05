// ##Approach: Since we know that the majority element will be present for count > size/2 times , therefore if we try an approach to cancel dissimilar elements with each other, then at last there will be only majority element left because its count is more than size/2 and there will be not much elements to fully cancel it.
// So, whenever we get count=, we update our elem to be that array element and if now any array element = elem then, we decrement the count. Like this we cancel each and every element except majority. and at last majority element will be left and stored in elem variable.

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
