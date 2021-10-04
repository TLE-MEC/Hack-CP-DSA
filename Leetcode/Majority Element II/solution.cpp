/*
    Time Complexity: O(n)
    Space Complexity:O(n)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size()/3;
        unordered_map<int , int> m;
        // Finding the number of times a particular element has appeared
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])==m.end())
                m[nums[i]]=1;
            else
                m[nums[i]]++;
        }
        vector<int> v;
        // Checking whether a particular number is repeated more than (n/3) times where n=size of the array
        for(auto &it:m )
        {
            if(it.second > n)
                v.push_back(it.first);//storing the elments which has appeared more than (n/3) times
        }
        return v;
    }
};