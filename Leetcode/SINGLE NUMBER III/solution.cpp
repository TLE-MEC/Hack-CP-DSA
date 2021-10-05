class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>p;     //created vector to store values
        unordered_map<int,int>mp;   // created map to store nums element and their frequency
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;   // inserted elements into ma
        }
        for(auto i:mp)
        {
            if(i.second==1)          //checked for frequency of each element of map where it is one.
                p.push_back(i.first);   //insert that element of nums into vector p
        }
        return p;                        //return vector p as a result
    }
};