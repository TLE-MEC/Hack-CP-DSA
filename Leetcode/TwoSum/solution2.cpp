class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       int size=nums.size(); //storing sizr of nums array
        vector<int>save(2); //initialising an array with size 2
        int i,j;
        j=0;
        int temp;
        for(i=0;i<size;i++)
        {
            for(j=i+1;j<size;j++)
            {
                temp=nums[i]+nums[j]; //nested for loop and storing sum of current and next element in temp
                if (temp==target) //comparing if temp is eaual to target
                    {
                        save[0]=i;
                        save[1]=j;
                        break;
                    }
            }
        }
        return save;
            
    }
};
